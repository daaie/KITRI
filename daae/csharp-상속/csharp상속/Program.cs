using System;
using System.Collections.Generic;
using System.Text;
//인터 페이스는 변수도 포함할 수 없고 몽땅다 추상 메소드
//추상 클래스가 꼭 다 추상메소드일필요는 없지만..
//추상클래스는 접점역할을 함..
namespace csharp상속
{

    class Parent
    {
        public int x;
        public int y;

        public Parent()
        {
            Console.WriteLine("Parent 생성");
        }
        public void test1()
        {
            Console.WriteLine("Parent : test1");
        }
        public virtual void test_1()
        {
            Console.WriteLine("Parent : test_1");
        }

        public void test2()
        {
            Console.WriteLine("Parent : test2");
        }
    }
    class child : Parent
    {
        public new int x = 3;
        public new int y = 4;  //부모거는없는걸로 치고 내가 새롭게 만들겠당,..

        public child()
        {
            Console.WriteLine("Child 생성");
        }
        public new void test1()
        {
            base.test1(); //클래스 안에서만base써야함 
            Console.WriteLine("Child : test1");
        }
        public override void test_1()
        {
            base.test_1(); //클래스 안에서만base써야함 
            Console.WriteLine("Child : test_1");
        }
        public new void test2()
        {
            base.test2(); //클래스 안에서만base써야함 
            Console.WriteLine("Child : test2");
        }
        public void test3()
        {
            Console.WriteLine("Parent : x+y={0}", base.x + base.y); //베이스 하면 부모클래스의 객체임.부모의 참조값을 갖는 참조변수
            //this 처럼..this 는 자신의 참조값을 갖는 참조변수
            Console.WriteLine("Child : x+y={0}", x + y);
        }
    }
    //프라이빗이랑 생성자는 상속 못받음..
    class Program
    {
        static void Main(string[] args)
        {
            // base 나 this 는 design 타임에서 써야함
            // 실행중에는 객체가있으니까 객체이름.머머 라고 쓰면됨
            //클래스 안에서만base써야함 
            child c = new child();
            //하위 클래스를 생성하면 제일 먼저 오브젝트 객체 생성
            //그다음 부모 생성되고 자식생성됨
            c.x = 10;
            c.y = 20;
            c.test1();
            c.test2();
            c.test3();
            Parent p = new child(); //upcasting 자식타입을 부모타입으로 올렸음..
            p.test1();  //부모거 실행함.. new는 정적결합->컴파일시에 결정됨 이때는 무조건 데이터 타입을 따름.부모거 
            p.test_1(); //자식거 샐행함.. 동적으로 실행결합->실행시에 결정됨 이때는 객체의 모양 보고 실행.자식거
            //업캐스팅 행세는 부모걸 하기때문에 
            //부모에 없는 함수나 멤버변수는 사용할 수 없음.
            //자식에 포함된 test3를 사용하려면 다운캐스팅해야함..
            //다운캐스팅은 한번 업캐스팅한거만 가능함.
            ((child)p).test3();
            //다운캐스팅은 캐스팅 연산자로하면됨
        }
    }
}
