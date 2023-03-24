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
        static Dictionary<string, string> _installedList = new Dictionary<string, string>();

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
                // 디스플레이 이름이 없는 경우도 존재한다. 그리고 32,64 bit 중복되어 키저장되어 있는게 몇개있다.
                string dp = subkey.GetValue("DisplayName").ToString() ?? keyName;
                string installDate = subkey.GetValue("EstimatedSize").ToString() ?? "unKnown";
                
                _installedList.Add(dp,installDate);
            }
        }
    }
}
