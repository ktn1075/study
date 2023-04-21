using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExZeroMq
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Pub pub = new Pub();
            pub.Start();

        }
    }
}
