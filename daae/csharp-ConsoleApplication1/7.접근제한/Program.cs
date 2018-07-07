using System;
using System.Collections.Generic;
using System.Text;

namespace _.접근제한
{
    class Test
    {
        private int x;
        private int y;

        public Test(int a, int b)
        {
            x = a;
            y = b;
        }
        //public void SetX(int a)
        //{
        //    x = a;
        //}
        //public void SetY(int a)
        //{
        //    y = a;
        //}
        //public int GetX()
        //{
        //    return x;
        //}
        //public int GetY()
        //{
        //    return y;
        //}

        //C#은 세터 게터 말고 프라이빗 변수에 접근하게 해주는 함수가있댱..

        public int X    //이거선언 멤버변수랑 똑같이 x를 해주면 중복이 되서 에러
        {
            get
            {
                return x;
            }
            set
            {
                x = value;
            }
        }
        public int Y
        {
            get
            {
                return y;
            }
            set
            {
                y = value;
            }
        }

        public void print()
        {
            Console.WriteLine("{0}",x);
            Console.WriteLine("{0}",y);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Test t1=new Test(1,2);
            t1.X = 10;  
            Console.WriteLine("t1.x={0}", t1.X);
            Console.WriteLine("t1.y={0}", t1.Y);

            //t1.SetX(10);
            //Console.WriteLine("t1.x={0}", t1.GetX());
            //Console.WriteLine("t1.y={0}", t1.GetY());

        }
    }
}
