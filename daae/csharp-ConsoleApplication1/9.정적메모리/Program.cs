using System;
using System.Collections.Generic;
using System.Text;

namespace _.정적메모리
{
    class Test
    {
        public static int x; //x는 스태틱메모리에 따로 저장.얜 테스ㅌ트 클래스 안에 있다고 생각하기 어렵다
        public int y;
        public Test()
        {
            x = 0;
            y = 0;
        }

        public void test1()
        {
            x++;
            y++;
            test2(); //일반 메소드에서 스태틱 메소드 호출 ㅇㅋ
            Console.WriteLine("x={0} ,y={1}", x , y); //일반변수 스태틱변수 호출 ㅇㅋ
        }

        public static void test2()
        {
            //test1(); //객체가없으면 사용못함..스태틱 메소드에서 일반메소드 호출 안댐
            //Console.WriteLine("x+y={0}", x+y); // 객체가 없으면 사용못함 y가있으면 에러남
            Console.WriteLine("x+y={0}", x );
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            //멤버변수 초기화안할경우 숫자타입은 0 객체타입은 null임
            Test t1 = new Test();
            t1.test1();
            Test t2 = new Test();
            t2.test1();
            Test t3 = new Test();
            t3.test1();
           // Test.x = 10;  //x는 객체 생성과 상관없음..클래스.변수
          //  t1.y = 20;
           // Test.test2(); //얘도 객체 생서안해도 사용가능
          //  t1.test1();
            // t1.y = 20;
        }
    }
}
