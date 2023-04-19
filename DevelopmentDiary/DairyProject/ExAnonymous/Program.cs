using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExAnonymous
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<string> hpList = new List<string>();

            var Hpinfo = new
            {
                Hpnumber = "010-3076-4788",
                date = DateTime.Now.ToString("yyyy-mm"),
                name = "kim",
                used = true,
                hpList
            };


            dynamic tdynamic = test2();

        }

        static object test2()
        {
            return new
            {
                Hpnumber = "010-3076-4788",
                date = DateTime.Now.ToString("yyyy-mm"),
                name = "kim",
                used = true,
            };
        }

    }
}
