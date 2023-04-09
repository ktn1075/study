﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;

namespace Ch06
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*
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
            */

            exThread();

        }

        static void exFile()
        {
            // 간단한 파일 처리 
            using (FileStream fs = new FileStream("test.log", FileMode.Create))
            {
                StreamWriter sw = new StreamWriter(fs, Encoding.UTF8);
                sw.WriteLine("hello word");
                sw.Write(32000);
                sw.Flush(); 
            }
            // 파일 복사
            File.Copy("test.log",@"C\test.log",true);
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

        static void exThread()
        {
            Console.WriteLine("exThread" + ":" + Environment.CurrentManagedThreadId);

            Thread t1 = new Thread(thread1test);
            t1.Start("test1");

            Thread t2 = new Thread(thread1test);
            t2.IsBackground = true;
            t2.Start("test2");

        }

        static void thread1test(object initValue)
        {
            Thread.Sleep(2000);
            string x = initValue as string;
            
            Console.WriteLine(x+":"+ Environment.CurrentManagedThreadId);
        }
    }
}
