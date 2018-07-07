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
        public delegate int del();
        public static int test1()
        {
            return 1;
        }

        static void Main(string[] args)
        {
            //대리자 객체 생성
            int x=0,y=0;
            del A;
            A = new del(test1);
            x=A();
            Console.WriteLine("x={0}",x);
            del B = delegate()
            {
                Console.WriteLine("==========");
                Console.WriteLine("익명");
                return 1;
            };
            y=B();
            Console.WriteLine("y={0}", y);
        }
    }
}
//버튼클릭이나 사건발생 - 이벤트 발생 할때 핸들러..
//버튼 클릭 ->핸들러가 여러개일경우 순차적으로 함수가 호출되야함..->델리게이트 ㅎ연산함..
//