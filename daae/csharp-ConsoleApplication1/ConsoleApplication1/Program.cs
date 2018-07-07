using System;
using System.Collections.Generic;
//collections 네임스페이스 큐,비트,배열,해시테이블
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args) //static -> 객체를 생성하지 않고 접근가능하니까..메인은 그래서 static
        {                               //타입[] ->배열타입..스트링 배열임 여기선.
                                        //배열이 사용할메모리 할당받으려면 new써야함..얘도 힙영역..
            string name = "aaa";
            int age ;
            float x ;
            Console.Write("name:");
            name = Console.ReadLine(); //리드라인은 무조건 문자열
            age = Int32.Parse(Console.ReadLine());
                                       //Int32 -> 기본형 인트형의 클래스타입
            x = Single.Parse(Console.ReadLine());
            Console.WriteLine("name={0},age={1},x={2}",name,age,x);
                                       //중괄호 {index} ->나열할 순서
                                       //콘솔객체의 WriteLine은 static이라는 소리..
                                       //Write와 WriteLine의 차이는 개행문자
        }
    }
}
//기본형..
//sbyte(1) 음수가능 바이트
//ubyte(1) 양수만가능 바이트
//short(2) , ushort(2)
//int(4), uint(4)
//long(8), ulong(8)
//char(2) ->유니코드라서 두바이트
//bool(1)
//float(4)
//double(8)
//enum->null형 상수

//객체형
//string, object
//object클래스는 C#에서 사용되는 모든 클래스의 조상임..모든 클래스는 object를 상속받음..