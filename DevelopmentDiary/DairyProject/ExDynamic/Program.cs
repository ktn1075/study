using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace ExDynamic
{
    internal class Program
    {
        static void Main(string[] args)
        {
            dynamic a = 1;
            Console.WriteLine(a.GetType());

            a = "aa";
            Console.WriteLine(a.GetType());

            a = 10;
            a = 10 + 20;

            Console.WriteLine(a);

            dynamic test =  M1();

            test.Display();
            test.ChangeAge(30);
        }

        public static dynamic M1()
        {
            dynamic person = new ExpandoObject();

            person.Name = "kim";
            person.Age = 10;

            person.Display = (Action)(() =>
            {
                Console.WriteLine("{0} {1}", person.Name, person.Age);
            });

            person.ChangeAge = (Action<int>)((age) => {
                person.Age = age;
                if (person.AgeChanged != null)
                {
                    person.AgeChanged(person, EventArgs.Empty);
                }
            });

            person.AgeChanged = null;

            person.AgeChanged += new EventHandler(OnAgeChanged);

            return person;
        }
        private static void OnAgeChanged(object sender, EventArgs e)
        {
            Console.WriteLine("Age changed");
        }
    }
    class Class1
    {
        public void Run()
        {
            dynamic t = new { Name = "Kim", Age = 25 };
            var t2 = new { Name = "Kim", Age = 25 };

            var c = new Class2();
            c.Run(t);
            c.Run(t2);
        }
    }

    class Class2
    {
        public void Run(dynamic o)
        {
            Console.WriteLine(o.Name);
            Console.WriteLine(o.Age);
        }
    }
}
