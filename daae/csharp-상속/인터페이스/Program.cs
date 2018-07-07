using System;
using System.Collections.Generic;
using System.Text;

namespace 인터페이스
{
    //인터페이스는 순수한 추상 클래스
    interface Test//인터페이스 내부 함수는 구현되어있으면 에러임..추상클래스는 객체를 못가진다
    {
        void test1();
        void test2();
    }
    abstract class Test2 : Test //추상메소드 다 구현안헀으니까 추상클래스임
    {
        public void test1() //인터페이스는 오버라이드 키워드 필요없음
        {
            Console.WriteLine("test1");
        }
        //public void test2()
        //{
        //    Console.WriteLine("test2");
        //}
    }
    class Test3 : test2
    {
        public void test2()
        {
            console.writeline("test2");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Test t = new Test3();
            t.test1();
            t.test2();
        }
    }
}
