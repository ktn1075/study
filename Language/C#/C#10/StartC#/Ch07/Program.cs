using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ch07
{
    internal class Program
    {
        static void Main(string[] args)
        {


        }

        static void ExGeneriy()
        {
            List<string> strings = new List<string>();
            List<int> ints = new List<int>();
        
          ints.Add(1);
        
        }
    }

    public class SStack<T>
    {
        T[] _objs;
        int _pos;

        public SStack(int size) { _objs = new T[size]; }

        public void Push(T newValue)
        {
            _objs[_pos] = newValue;
            _pos++;
        }

        public T Pop()
        {
            _pos--;
            return _objs[_pos];
        }

        public static T SMax<T>(T item1, T item2) where T : IComparable
        {
            if (item1.CompareTo(item2) >= 0)
            {
                return item1;
            }

            return item2;
        }

        public static int S2<T>(T item1) where T : struct
        {

            return Marshal.SizeOf(item1);
        }

        public static T S3<T>(T item1, T item2) where T : class
        {
            if (item1 == null)
            { return item2; }

            return item2;
        }

    }

}
