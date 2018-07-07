using System;
using System.Collections.Generic;
using System.Text;
//c# 에서의 delegate는 c에서의 함수포인터
//c에서 포인터 배열에서 각 함수의 주소값을 저장하고 있다가 이벤트가 발생하면 주소값으로 함수 ㅎ호출...
//look up table
namespace csharp_delegate
{
    class Program
    {
        //대리자 정의
        public delegate void del(string s);
        //대리자로 호출할 함수 - 델리게이트를 적용할 함수
        public static void test1(string str)
            //객체 만들기 귀찮아서 스태틱으로 만듬..
            //델리게이트 함수랑 반환타입과 매개변수가 같아야함
        {
            
            Console.WriteLine("test1 "+str);
        }
        public static void test2(string str)
        {

            Console.WriteLine("test2 " + str);
        }
        public static void test3(string str)
        {

            Console.WriteLine("test3 " + str);
        }

        static void Main(string[] args)
        {
            //대리자 객체 생성
            del A,B,C,D;
            A = new del(test1);
            B = new del(test2);
            C = new del(test3);
            //대리자로 함수호출
            D = A + B + C;
            D("ddd");
            Console.WriteLine("===========");
            D -=B;
            D("ddd");

            del E = delegate (string s)  //타입은 맞춰줘야함..void 어디감...
            {
                Console.WriteLine("익명 메서드");
                Console.WriteLine(s);
            };//함수를 한번만 쓰고 버릴거야...이름없는 메서드 타입은 맞춰줘야함

            E("asdf");
        }
    }
}
//=========사용 예시===============
//버튼클릭이나 사건발생 - 이벤트 발생 할때 핸들러..
//버튼 클릭 ->핸들러가 여러개일경우 순차적으로 함수가 호출되야함..->델리게이트 ㅎ연산함..
