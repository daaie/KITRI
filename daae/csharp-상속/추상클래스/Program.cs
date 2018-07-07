using System;
using System.Collections.Generic;
using System.Text;

namespace 추상클래스
{
    abstract class GrandParent
    {

        public abstract void test1();
        public abstract void test2();
        public void test3()
        {
            Console.WriteLine("test3");
        }
    }
    abstract class Parent : GrandParent
    {
        public override void test1()
        {
            Console.WriteLine("test1");
        }
        //상속받는 하위에서 상속받는 모든 추상 메소드를 구현하지 않으면
        //하나라도 추상 메소드를 구현안하면 그 클래스는 추상 클래스가된다.
    }
    sealed class Child : Parent //실드는 상속을 못하게 막는거  ...코드에 의해 생성되는데 변하면 안되는 값들..
    {
        public override void test2()
        {
            Console.WriteLine("test2");
        }
    }
    class Test : Child
    {

    }
    class Program
    {
        //완성된 객체는 차읻르 밖에없음...나머지는 추상 클래스임
        //차일드를 구현함
        //추상클래스는 객체를 못가짐
        static void Main(string[] args)
        {
            Child c = new Child(); //or Parent c = new Child();
            c.test1();
            c.test2();
            c.test3();
        }
    }
}
