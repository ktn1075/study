using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ch05
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*   a는 지역변수이므로 스택이 할당되고 스택 메모리에 5값이 들어간다.
             *   obj 는 지역변수고 스택에 할당된다. 하지만 object 참조형 이기 때문에 힙에도 메모리가 할당되고 변수 a의 값이 들어간다. (박싱)
             *   obj 지역변수는 힙에 할당된 주소를 가리킨다.
             *   b는 지역변수이므로 스택이 할당되고 해당 영역에 힙 메모리에 있는 값을 스택 메모리로 복사한다. (언박싱)
             */
            int a = 5;
            object obj = a;
            int b = (int)obj;

            // 처음 new 할당된 객체는 0세대 이다. GC를 통해 확인가능.
            Program pg = new Program();
            Console.WriteLine(GC.GetGeneration(pg)); // 출력결과 0 



            // CLR의 객체의 세대는 2세대 까지이며, 그 이후 시스템이 허용하는 한 메모리의 크기가 계속 커지게된다;
            object pgo = new object();
            Console.WriteLine(GC.GetGeneration(pg));  // 0

            GC.Collect();
            Console.WriteLine(GC.GetGeneration(pg));  // 1

            GC.Collect();
            Console.WriteLine(GC.GetGeneration(pg));  // 2

            GC.Collect();
            Console.WriteLine(GC.GetGeneration(pg));  // 2


            // 업그레이드 된 GC 예제

            object aa = new object();
            object bb = new object();
            object cc = new object();

            dome();
            GC.Collect();


            // using 사용해서 무조건 Dispose 호출 되도록 수정 
            using (FileLogger f = new FileLogger("x"))
            {


            }

        }
        private static void dome()
        {
            object d = new object();
            object e = new object();
            object f = new object();
            object g = new object();

            d = null;
            e = null;

            GC.Collect();

            object h = new object();
            object i = new object();

            object j = new object();
            object k = new object();

            j = null;
            k = null;

            GC.Collect();
        }

        private static void FileCreate()
        {
            FileStream fs = new FileStream("test", FileMode.Create);
            fs.Dispose();
        }

    }

    class FileLogger : IDisposable
    {
        FileStream _fs;

        public FileLogger(string filename)
        {
            _fs = new FileStream(filename, FileMode.Create);
        }

        public void Dispose()
        {
            Console.WriteLine("dispose 호출 ");
            _fs.Close();
        }
    }


    class FileLogger2
    {
        FileStream _fs;

        public FileLogger2(string filename)
        {
            _fs = new FileStream(filename, FileMode.Create);
        }

        ~FileLogger2()
        {
            _fs.Dispose();
        }

        public void Dispose()
        {
            _fs.Close();
        }
    }
}
