using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace FormatString
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // SimpleString("test");
            //level2String();
            level3String();
        }
        
        static void SimpleString(string x)
        {
            Console.WriteLine($"매개변수는 {x}");
        }

        static void level2String()
        {
            StringBuilder sb = new StringBuilder();

            string t1 = "tttttttttttttttt";
            string t2 = "ttttttttttttttttttttttt2222222";
            string t3 = "tttttttttttttttttttttttttttttttttttttt";
            string t4 = "t23refafakwfawlfmawl";

            sb.AppendLine($"{t1, -40:C}{t2, 50:C}");  // 좌측으로 부터 정렬  , 우측으로 부터 정렬
            sb.AppendLine($"{t3, -40:C}{t4, 50:C}");

            string desktop_path = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);


            File.WriteAllText($@"{Path.Combine(desktop_path,"test.txt")}",sb.ToString());
        }

        static void level3String()
        {

            // 1. 문자열이 여러경우로 되어있는 경우 
            string tests = @"
                안녕하세요
                반갑습니다
                잘하고 싶어요 
            ";

            // 2. 정규식
            Regex letters = new Regex(@"[a-z]+\.\d+");

            // 3. 윈도우 운영체제의 파일이름

            string path = @"C:\";
        }
    }
}
