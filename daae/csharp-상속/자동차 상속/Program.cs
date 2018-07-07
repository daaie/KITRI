using System;
using System.Collections.Generic;
using System.Text;

namespace 자동차_상속
{
    class car
    {
        protected string name;
        protected int doors;

        public virtual void beep()
        {
            Console.WriteLine("빵빵");
        }
    }
    class 소방차 : car
    {
        public 소방차()
        {
            name = "소방차";
            doors = 3;
        }
        public override void beep()
        {
            Console.WriteLine("dldhdldh");

        }
        public void 물대포()
        {
            Console.WriteLine("물대포");
        }
    }
    class 굴착기 : car
    {
        public 굴착기()
        {
            name = "굴착기";
            doors = 2;
        }
        public override void beep()
        {
            Console.WriteLine("znfmfm");

        }
        public void 땅파기()
        {
            Console.WriteLine("땅파기");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            bool flag = true;
            int menu;
            car c = null;
            while (flag)
            {
                Console.WriteLine("1.소방차 , 2.굴착기, 3.종료");
                menu = Int32.Parse(Console.ReadLine());
                switch (menu)
                {
                    case 1: c = new 소방차();
                        c.beep();
                        ((소방차)c).물대포();
                        break;
                    case 2:
                        c = new 굴착기();
                        c.beep();
                        ((굴착기)c).땅파기();
                        break;
                    case 3:
                        flag = false;
                        break;

                }
            }

        }
    }
}
