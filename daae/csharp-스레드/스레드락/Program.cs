using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace 스레드락
{
    class Test
    {
        private int num = 0;
        public void add()
        {
            for (int i = 0; i < 10; i++)
            {
                lock (this)
                {
                    Thread.Sleep(1);
                    Console.WriteLine("num(add):{0}", ++num);
                   
                }
            }
        }
        public void sub()
        {
            for (int i = 0; i < 10; i++)
            { 
                lock (this) //락만큼 실행하는동안 접근못하게
                {
                    Thread.Sleep(1);
                    Console.WriteLine("num(sub):{0}", --num);
  
                }
            }
        }
        public void test()
        {
            Thread t1 = new Thread(new ThreadStart(add));
            Thread t2 = new Thread(new ThreadStart(sub));
            t1.Start();
            t2.Start();
            //t1.Join(); //끝나는거 기다ㅕ줌
            //t2.Join();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Test t1 = new Test();
            t1.test();
        }
    }
}
