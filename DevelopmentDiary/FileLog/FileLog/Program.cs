using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileLog
{
    internal class Program
    {
        private static readonly string DST_TARGET = @"C:\Users\ktn10\Desktop";

        private static void FileCy(string source , string dst , bool re)
        {
            if(Directory.Exists(source))
            {
                foreach (var item in Directory.GetDirectories(source))
                {

                }
            }
            
            if(File.Exists(source))
            {

            }
        }

        static void Main(string[] args)
        {
            string targetDirectoryLocalAppdata = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData);

            string targetDirectoryCommonApplicationData = Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData);

            string targetDoc = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);

            List<string> list = new List<string>();
            list.Add(targetDirectoryLocalAppdata);
            list.Add(targetDirectoryCommonApplicationData);
            list.Add(targetDoc);    

            foreach (string path in list) 
            { 
                    
            
            
            
            }
        }
    }
}
