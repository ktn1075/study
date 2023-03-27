using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace PrinterInfo
{
    internal class Program
    {
        // C#에서 지원하는 BCL 에서는 설치된 프린터이외에 설치된 드라이버를 가져오는 
        // 메서드는 없어서 winspool.drv 의 EnumPrinterDrivers 로 가져온다.
        [DllImport("winspool.drv", CharSet = CharSet.Auto, SetLastError = true)]
        static extern bool EnumPrinterDrivers(String pName, String pEnvironment, uint level, IntPtr pDriverInfo, uint cdBuf, ref uint pcbNeeded, ref uint pcRetruned);

        //Level 2수준의 정보를 가져오기 위해 해당 구조체도 선언해 준다.
        public struct DRIVER_INFO_2
        {
            public uint cVersion;
            [MarshalAs(UnmanagedType.LPTStr)]
            public string pName;
            [MarshalAs(UnmanagedType.LPTStr)]
            public string pEnvironment;
            [MarshalAs(UnmanagedType.LPTStr)]
            public string pDriverPath;
            [MarshalAs(UnmanagedType.LPTStr)]
            public string pDataFile;
            [MarshalAs(UnmanagedType.LPTStr)]
            public string pConfigFile;
        }


        static DRIVER_INFO_2[] GetPrinterDrivers()
        {
            uint cbNeeded = 0;
            uint cReturned = 0;
            if (EnumPrinterDrivers(null, null, 2, IntPtr.Zero, 0, ref cbNeeded, ref cReturned))
            {
                //succeeds, but shouldn't, because buffer is zero (too small)!
                throw new Exception("EnumPrinters should fail!");
            }

            int lastWin32Error = Marshal.GetLastWin32Error();
            //ERROR_INSUFFICIENT_BUFFER = 122 expected, if not -> Exception
            if (lastWin32Error != 122)
            {
                return null;
            }

            IntPtr pAddr = Marshal.AllocHGlobal((int)cbNeeded);
            if (EnumPrinterDrivers(null, null, 2, pAddr, cbNeeded, ref cbNeeded, ref cReturned))
            {
                DRIVER_INFO_2[] printerInfo2 = new DRIVER_INFO_2[cReturned];
                int offset = pAddr.ToInt32();
                Type type = typeof(DRIVER_INFO_2);
                int increment = Marshal.SizeOf(type);
                for (int i = 0; i < cReturned; i++)
                {
                    printerInfo2[i] = (DRIVER_INFO_2)Marshal.PtrToStructure(new IntPtr(offset), type);
                    offset += increment;
                }
                Marshal.FreeHGlobal(pAddr);

                return printerInfo2;
            }
            return null;
        }

        static void Main(string[] args)
        {
            DRIVER_INFO_2[] pdrivers = GetPrinterDrivers();

            foreach (var item in pdrivers)
            {
                Console.WriteLine("DriverName : {0}",item.pName);
            }
        }
    }
}
