using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace 모니터
{
    class Test
    {
        private int num;
        public void add()
        {
            while (true)
            {
                Monitor.Enter(this); //this는 공유자원임..다른 클래스의 공유자우너이면 객체넣어주면됨;
                num++;
                if (num >= 20)
                {
                    Monitor.Pulse(this);
                    Monitor.Wait(this);

                }
                Console.WriteLine("num add :      {0}", num);
                Monitor.Exit(this);
                Thread.Sleep(100);

            }
        }
        public void sub()
        {
            while (true)
            {
                Monitor.Enter(this); //this는 공유자원임..다른 클래스의 공유자우너이면 객체넣어주면됨;
                num--;
                if (num <= 0)
                {
                    Monitor.Pulse(this);
                    Monitor.Wait(this);

                }
                Console.WriteLine("num      sub  :{0}", num);
                Monitor.Exit(this);
                Thread.Sleep(100);

            }
        }
        public void test()
        {
            Thread t1 = new Thread(new ThreadStart(add));
            Thread t2 = new Thread(new ThreadStart(sub));
            t1.Start();
            t2.Start();
        }
    }
    class Program
    {

        static void Main(string[] args)
        {
            Test t = new Test();
            t.test();
        }
    }
}
