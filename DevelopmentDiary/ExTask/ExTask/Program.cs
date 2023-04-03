using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ExTask
{
    internal class Program
    {
        static void t1()
        {
            Console.WriteLine("t1");
        }

        static void t2()
        {
            Thread.Sleep(5000);
            Console.WriteLine("t2");
        }

        static void Main(string[] args)
        {
            // Action
            Task task1 = new Task( new Action(t2));
            task1.Start();

            //델리게이트
            Task task2 = new Task(delegate { t2(); });
            task2.Start();

            // 직접 호출
            Task.Factory.StartNew(t1);

            // 람다
            Task.Run(() => Console.WriteLine("t3"));

            //task2.Wait();
            
            IList<Task> writeTaskList = new List<Task>();

            writeTaskList.Add(task1);

            writeTaskList.Add(task2);

            Task.WhenAll(writeTaskList).Wait();
            
        }
    }
}
