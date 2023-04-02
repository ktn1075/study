using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ExInvoke
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Action<string> test = testF;
            test += testF2;

            test.Invoke("invoke");

            Console.WriteLine($"Invoke:::::Main : {Thread.CurrentThread.ManagedThreadId}");

            // beginInvoke

            Action<string> test11 = testF;

            IAsyncResult result = test11.BeginInvoke("BeginInvoke", null, null);

            Console.WriteLine($"BeginInvoke:::::Main : {Thread.CurrentThread.ManagedThreadId}");

            test11.EndInvoke(result);

        }
        
        public static void testF(string x)
        {
            Console.WriteLine($"{x}:::::+TestFunc : {Thread.CurrentThread.ManagedThreadId}");
        }

        public static void testF2(string x)
        {
            Console.WriteLine($"{x}:::::TestFunc2 : {Thread.CurrentThread.ManagedThreadId}");
        }
    }
}
