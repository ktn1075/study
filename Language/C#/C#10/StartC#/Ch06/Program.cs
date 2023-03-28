using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Ch06
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //DateTime 
            DateTime endofYear = new DateTime(DateTime.Now.Year, 12, 31);
            DateTime now = DateTime.Now;

            TimeSpan gap = endofYear - now;

            Console.WriteLine(gap.TotalDays);

            Stopwatch st = new Stopwatch();

            st.Start();

            for (int i = 0; i < 1000; i++)
            {
                Console.WriteLine(i);
            }

            st.Stop();

            Console.WriteLine(st.ElapsedMilliseconds);

            // 문자열 처리 

            // 문자열 포맷
            string txt = "hello {0}:{1}";
            Console.WriteLine(txt, "world", "aderson");

            /* stringbulider
             *  txt2 변수는 helloworld 가르키고 그 상태에서 tolower 호출하면 txt2 변수에 담긴 문자열이 소문자로 변경되는것이
             *  원문이 통째로 복사된 다음 그것이 소문자로 변경되어 반환되는 절차를 거친다.
             */
            string txt2 = "hello world";
            string format = txt2.ToLower();

            string txt3 = "hello world";

            Stopwatch st2 = new Stopwatch();

            st2.Start();

            for (int i=0; i< 100000; i++)
            {
                txt3 = txt3 + i;
            }

            st2.Stop();


            Stopwatch st3 = new Stopwatch();

            Console.WriteLine(st2.ElapsedMilliseconds);

            st3.Start();

            StringBuilder sb = new StringBuilder();
            sb.AppendLine("hello world");

            for (int i = 0; i < 100000; i++)
            {
                sb.Append(i);
            }

            st3.Stop();

            Console.WriteLine(st3.ElapsedMilliseconds);

            // exRegex();


            exCollection();

        }

        static void exEncdoing()
        {
            string textData = "helloworld";
            byte[] buf = Encoding.UTF8.GetBytes(textData);
            
            string textData2 =  Encoding.UTF8.GetString(buf);
        }

        static void exRegex()
        {
            // 간단한 이메일 파싱
            string email = "ktn1075@naver.com";

            Regex regex = new Regex(@"^([0-9a-zA-Z]+)@([0-9a-zA-Z]+)(\.[0-9a-zA-Z]+){1,}$");
            bool t = regex.IsMatch(email);
           
            if (t) { Console.WriteLine("이메일"); }
        }


        static void exCollection()
        {

            ArrayList ar = new ArrayList();
            ar.Add("hello");
            ar.Add(15);

            if(ar.Contains(15))
            {
                Console.WriteLine("존재");
            }

            ar.Remove(15);

            // Hashtable

            Hashtable ht = new Hashtable();

            ht.Add("key",10);

            Console.WriteLine(ht["key"]);

            // SortedList

            SortedList sl =new SortedList();

            sl.Add(5,10);
            sl.Add(3, 12);
            sl.Add(4, 15);

            foreach (var item in sl.GetKeyList())
            {
                Console.WriteLine(sl[item]);
            }

            // stack 

            Stack st = new Stack();

            st.Push("hello");
            st.Push("hello2");

            var test22 = st.Pop();

            Console.WriteLine(test22);


            // queue 

            Queue q =   new Queue();

            q.Enqueue("hello1");
            q.Enqueue("hello2");
            
            var test33 = q.Dequeue();

            Console.WriteLine(test33);


        }
    }
}
