using System;
using System.Collections.Generic;
using System.Linq;
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
    }

}
