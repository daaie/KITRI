using System;
using System.Collections.Generic;
using System.Text;

namespace _.객체
{
    class Test
    {
        public int x;
        public int y;
    }
    class Program
    {
        static void Main(string[] args)
        {
            Test t1 = new Test();
            t1.x = 10;
            t1.y = 20;
            Test t2 = new Test();
            t2.x = 30;
            t2.y = 40;
            Test t3 = t1; //C++에서는 Test t3만 선언해도 스택에 할당받음..C#은 못받는다
            t3.x = 1;
            t3.y = 2;

            Console.WriteLine("t1.x={0}, t1.y={1}", t1.x, t1.y);
            Console.WriteLine("t2.x={0}, t2.y={1}", t2.x, t2.y);
            Console.WriteLine("t3.x={0}, t3.y={1}", t3.x, t3.y);
            Console.WriteLine("t1={0}, t1.hashcod={1}", t1, t1.GetHashCode());
            Console.WriteLine("t2={0}, t2.hashcod={1}", t2, t2.GetHashCode());
            Console.WriteLine("t3={0}, t3.hashcod={1}", t3, t3.GetHashCode());
            //모든 클래스는 Object를 상속받음.
            //Object내부에 Tostring이랑 GetHashcod 메소드 있음
            //Tostring은 객체를 찍으면 해당 객체의 데이터 타입 반환
            //GetHashCode는 해당 객체의 참조변수 반환
            
        }
    }
}
