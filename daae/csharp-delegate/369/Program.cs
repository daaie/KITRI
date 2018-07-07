using System;
using System.Collections.Generic;
using System.Text;

namespace _69
{
    class Test
    {
        public delegate bool del();
        public del myEvent;
        public Test(del myEvent)
        {
            this.myEvent = myEvent;
        }
        public void cnt()
        {
            int number = 0,cnt=0,number2;
            string imsi;
            bool check=false;
            while (true)
            {
                number++;
                imsi = Convert.ToString(number);
                cnt = imsi.Length;

                number2 = number;

                for (int i = 0; i < cnt; i++)
                {
                    if (number2 % 10 == 3 || number2 % 10 == 6 || number2 % 10 == 9)
                    {
                         check=myEvent();
                    }
                    number2 /= 10;
                }
                if (check == false)
                {
                    Console.Write("{0}  ", number);
                }
                check = false;
                System.Threading.Thread.Sleep(300);
            }
        }
    }
    class Program
    {
        public static bool handler()
        {
            Console.Write("(¦)  ");
            return true;
        }
        static void Main(string[] args)
        {
            Test test = new Test(new Test.del(handler));
            test.cnt();
        }
    }
}
