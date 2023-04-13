using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ExException
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Environment.CurrentManagedThreadId);
            try
            {
                test1();
                //test2();
                //test3();
                //test4();

                
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            while(true)
            {
                Thread.Sleep(100);
                Console.WriteLine(Environment.CurrentManagedThreadId);
            }
        }

        static async void test1()
        {
            Console.WriteLine(Environment.CurrentManagedThreadId);

            await Task.Run(() => { throw new Exception("tttttttttttttttttttttt"); });

            Console.WriteLine(Environment.CurrentManagedThreadId);

        }
        static async void test2()
        {
            try
            {
                throw new Exception("tttttttttttt222");
                await Task.Run(() => { Console.WriteLine("test2"); });
            }
            catch (Exception e) 
            {
                
            }
        }
        static void test3()
        {
            throw new Exception("error");
        }

        static async Task test4()
        {
            try
            {
                throw new Exception("ttt2222222222222224");
                await Task.Run(() => { Console.WriteLine("test4"); });
            }
            catch(Exception e)
            {
                ;
            }
        }
    }
}
