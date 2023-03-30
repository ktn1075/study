using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection.Emit;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace ExEelegate
{
    internal class Program
    {
        public delegate int DETEST (string x);

        public static int test1(string x)
        {
            Console.WriteLine("test1");
            return int.Parse(x)+1;
        }

        public static int test2(string x)
        {
            Console.WriteLine("test2");
            return int.Parse(x)+2;
        }

        static void Main(string[] args)
        {
            DETEST dETEST = test1;
            dETEST += test2;

            int result = dETEST("10");

            Console.WriteLine(result);

            Console.WriteLine("==================================");

            Delegate[] dels = dETEST.GetInvocationList();

            foreach (Delegate d in dels)
            {
                DETEST f = (DETEST)d;
                int ret = f("10");
                Console.WriteLine(ret);
            }
        }
    }
}
