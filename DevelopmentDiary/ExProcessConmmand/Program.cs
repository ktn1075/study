using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Management;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ExProcessConmmand
{
    internal class Program
    {
        static Dictionary<string,string> _processInfo = new Dictionary<string, string>();

        static void Main(string[] args)
        {
            Stopwatch sw = Stopwatch.StartNew();

            sw.Start();

            CommandLineWmi();

            StringBuilder sb = new StringBuilder();

            foreach (Process process in Process.GetProcesses())
            {
                string cmd = "";
                //int rc = GetCommandLine(process, out cmd);

                cmd = _processInfo[process.Id.ToString()];

                sb.Append($"{process.ProcessName,-60}{process.Id,-10}{process.SessionId,-5}{process.WorkingSet64 / 1000 + "kb",-10}");
                sb.AppendLine($"{cmd,-100}");
            }

            Console.WriteLine( sb.ToString() );

            sw.Stop();
            
            Console.WriteLine( sw.ElapsedMilliseconds);
        }

        public static void CommandLineWmi()
        {
            using
            (
                ManagementObjectSearcher searcher = new ManagementObjectSearcher
                (
                    "SELECT ProcessId,CommandLine FROM Win32_Process"
                )
            )
                foreach (ManagementObject obj in searcher.Get())
                {

                    string processid = obj["ProcessId"].ToString() as string; 
                    string commandLine = obj["CommandLine"] as string;

                    _processInfo[processid] = commandLine;
                }
        }

        [DllImport("kernel32.dll", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool CloseHandle(IntPtr hObject);

        public const uint PROCESS_BASIC_INFORMATION = 0;

        [Flags]
        public enum OpenProcessDesiredAccessFlags : uint
        {
            PROCESS_VM_READ = 0x0010,
            PROCESS_QUERY_INFORMATION = 0x0400,
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct ProcessBasicInformation
        {
            public IntPtr Reserved1;
            public IntPtr PebBaseAddress;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2)]
            public IntPtr[] Reserved2;
            public IntPtr UniqueProcessId;
            public IntPtr Reserved3;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct UnicodeString
        {
            public ushort Length;
            public ushort MaximumLength;
            public IntPtr Buffer;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct PEB
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
            public IntPtr[] Reserved;
            public IntPtr ProcessParameters;
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct RtlUserProcessParameters
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
            public byte[] Reserved1;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 10)]
            public IntPtr[] Reserved2;
            public UnicodeString ImagePathName;
            public UnicodeString CommandLine;
        }

        [DllImport("ntdll.dll")]
        public static extern uint NtQueryInformationProcess(
    IntPtr ProcessHandle,
    uint ProcessInformationClass,
    IntPtr ProcessInformation,
    uint ProcessInformationLength,
    out uint ReturnLength);

        [DllImport("kernel32.dll")]
        public static extern IntPtr OpenProcess(
            OpenProcessDesiredAccessFlags dwDesiredAccess,
            [MarshalAs(UnmanagedType.Bool)] bool bInheritHandle,
            uint dwProcessId);

        [DllImport("kernel32.dll")]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool ReadProcessMemory(
            IntPtr hProcess, IntPtr lpBaseAddress, IntPtr lpBuffer,
            uint nSize, out uint lpNumberOfBytesRead);

        [DllImport("shell32.dll", SetLastError = true,
            CharSet = CharSet.Unicode, EntryPoint = "CommandLineToArgvW")]
        public static extern IntPtr CommandLineToArgv(string lpCmdLine, out int pNumArgs);


        private static bool ReadStructFromProcessMemory<TStruct>(IntPtr hProcess, IntPtr lpBaseAddress, out TStruct val)
        {
            val = default;
            var structSize = Marshal.SizeOf<TStruct>();
            var mem = Marshal.AllocHGlobal(structSize);
            try
            {
                if (ReadProcessMemory(
                    hProcess, lpBaseAddress, mem, (uint)structSize, out var len) &&
                    (len == structSize))
                {
                    val = Marshal.PtrToStructure<TStruct>(mem);
                    return true;
                }
            }
            finally
            {
                Marshal.FreeHGlobal(mem);
            }
            return false;
        }

        private static int GetCommandLine(Process process, out string commandLine)
        {
            int rc = 0;
            commandLine = null;

            var hProcess = OpenProcess(
                OpenProcessDesiredAccessFlags.PROCESS_QUERY_INFORMATION |
                OpenProcessDesiredAccessFlags.PROCESS_VM_READ, false, (uint)process.Id);

            if (hProcess != IntPtr.Zero)
            {
                try
                {
                    var sizePBI = Marshal.SizeOf<ProcessBasicInformation>();
                    var memPBI = Marshal.AllocHGlobal(sizePBI);
                    try
                    {
                        var ret = NtQueryInformationProcess(
                            hProcess, PROCESS_BASIC_INFORMATION, memPBI,
                            (uint)sizePBI, out var len);
                        if (0 == ret)
                        {
                            var pbiInfo = Marshal.PtrToStructure<ProcessBasicInformation>(memPBI);
                            if (pbiInfo.PebBaseAddress != IntPtr.Zero)
                            {
                                if (ReadStructFromProcessMemory<PEB>(hProcess,
                                    pbiInfo.PebBaseAddress, out var pebInfo))
                                {
                                    if (ReadStructFromProcessMemory<RtlUserProcessParameters>(
                                        hProcess, pebInfo.ProcessParameters, out var ruppInfo))
                                    {
                                        var clLen = ruppInfo.CommandLine.MaximumLength;
                                        var memCL = Marshal.AllocHGlobal(clLen);
                                        try
                                        {
                                            if (ReadProcessMemory(hProcess,
                                                ruppInfo.CommandLine.Buffer, memCL, clLen, out len))
                                            {
                                                commandLine = Marshal.PtrToStringUni(memCL);
                                                rc = 0;
                                            }
                                            else
                                            {
                                                // couldn't read command line buffer
                                                rc = -6;
                                            }
                                        }
                                        finally
                                        {
                                            Marshal.FreeHGlobal(memCL);
                                        }
                                    }
                                    else
                                    {
                                        // couldn't read ProcessParameters
                                        rc = -5;
                                    }
                                }
                                else
                                {
                                    // couldn't read PEB information
                                    rc = -4;
                                }
                            }
                            else
                            {
                                // PebBaseAddress is null
                                rc = -3;
                            }
                        }
                        else
                        {
                            // NtQueryInformationProcess failed
                            rc = -2;
                        }
                    }
                    finally
                    {
                        Marshal.FreeHGlobal(memPBI);
                    }
                }
                finally
                {
                    CloseHandle(hProcess);
                }
            }
            else
            {
                // couldn't open process for VM read
                rc = -1;
            }

            return rc;
        }
    }
}
