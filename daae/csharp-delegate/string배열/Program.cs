using System;
using System.Collections.Generic;
using System.Text;
//타입한정
namespace generic
{
    class Test
    {
        public string name;
        public Test(string name)
        {
            this.name = name;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            List<Test> t1 = new List<Test>();
            LinkedList<Test> t2 = new LinkedList<Test>();
            //링크드리스트는 배열에 비해 중간에 추가 삭제가 편리
            //배열은 뒤에 추가 쉬움,,?
            t1.Add(new Test("AAA"));
            t1.Add(new Test("BBB"));
            t1.Add(new Test("CCC"));
            t1.Insert(1, new Test("DDD"));
            t1.RemoveAt(3);
            //t1.RemoveAll();

            foreach (Test t in t1)
            {
                Console.WriteLine(t.name);
            }
            t1.Clear();
        }

    }
}
