using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProcessListGet
{
    internal class Program
    {
        static void Main(string[] args)
        {
            getProcess();
        }

        static void getProcess()
        {
            Process[] processes = Process.GetProcesses();

            foreach (Process p in processes)
            {
                Console.WriteLine($"PID:{p.Id} - NAME :{p.ProcessName}, SessionId : {p.SessionId}, Memory할당량:{p.WorkingSet64/1000}kb");
            }
        }
    }
}
