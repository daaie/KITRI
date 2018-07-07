using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
namespace 스레드생성
{
    class Program
    {
        public static void test1()
        {
            for (int i = 0; i < 26; i++)
            {
                Console.Write("{0}\t", i);
                Thread.Sleep(1);

            }
        }
        public static void test2()
        {
            for (int i = 'a'; i <= 'z'; i++)
            {
                Console.Write("{0}\t", (char)i);
                Thread.Sleep(1);
            }

        }
        //static이 아니면 실행ㅇ를못함....?!!!!!
        static void Main(string[] args)
        {
            Thread t1 = new Thread(new ThreadStart(test1));
            //ThreadStart는 델리게이트...
            //test1을 대리하는 새로운 델리게이트 생성..
            Thread t2 = new Thread(new ThreadStart(test2));
            t1.Start();
            //start()명령해야 준비상태.그래야 스케줄러가 준비중인 스레드 시작함
            t2.Start();
           
            //t2.Abort();
            //t1.Abort();
            //abort하면 스레드가 다실행안되도 바로 종료시켜 버림..언제 종료될진 아무도모름..
            //어쨋든 순서대로 종료됨

            t1.Join();
            t2.Join();
            //join 하면 쓰레드가 그 함수를 다 실행할때까지 안끝나고 기다려줌..

            Console.WriteLine("끝");
        }
    }
}
