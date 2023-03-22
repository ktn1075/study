using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace InstalledProgramList
{
    internal class Program
    {
        static List<string> _installedList = new List<string>();

        static void Main(string[] args)
        {
            string path = @"SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall";

            RegistryKey key;
            key = Registry.CurrentUser.OpenSubKey(path);

            FindProgram(key);

            key = Registry.LocalMachine.OpenSubKey(path);

            FindProgram(key);

            key = Registry.LocalMachine.OpenSubKey(@"SOFTWARE\Wow6432Node\Microsoft\Windows\CurrentVersion\Uninstall");

            FindProgram(key);

            int countx = 0;
            foreach (var item in _installedList)
            {
                Console.WriteLine($"{countx} : {item}");
                countx++;   
            }

            Console.WriteLine(_installedList.Count());   
        }

        static void FindProgram(RegistryKey key)
        {
            foreach (String keyName in key.GetSubKeyNames())
            {
                RegistryKey subkey = key.OpenSubKey(keyName);
                string dp = subkey.GetValue("DisplayName") as string;
                if (dp != null) 
                { _installedList.Add(dp); }
            }
        }
    }
}
