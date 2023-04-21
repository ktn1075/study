using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ZeroMqClient
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Sub sub = new Sub("tcp://127.0.0.1:55545", "Even");

            sub.setSubScriberName("Even");

            Thread t1 = new Thread(sub.listen);
 
            t1.Start();

            t1.Join();

        }
    }
}
