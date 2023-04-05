using System;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace AwaitAsync
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Thread.CurrentThread.ManagedThreadId);
            test1();
            while (true)
            {
                ;
            }
        }
         
        static async void test1()
        {
            Console.WriteLine(Thread.CurrentThread.ManagedThreadId);

            var task1 = Task.Run(() => test12());

            await task1.ConfigureAwait(false);

            Console.WriteLine(Thread.CurrentThread.ManagedThreadId);
        }

        static void test12()
        {
            Console.WriteLine(Thread.CurrentThread.ManagedThreadId);
            Thread.Sleep(5000);
        }
    }
}
