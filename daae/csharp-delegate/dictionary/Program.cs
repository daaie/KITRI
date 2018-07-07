using System;
using System.Collections.Generic;
using System.Text;

namespace dictionary
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
            //키랑 값이랑 두개 지정해줘야함
            Dictionary<int, string> d = new Dictionary<int, string>();
            //키값을 가지고 내부에서 해쉬코드... 난수를 만듬
            //해쉬코드를 기준으로 values(string)을 찾음
            //빠른검색을 제공..

            d.Add(1,"aaa");
            d.Add(2,"bbb");
            d.Add(3,"ccc");
            foreach (KeyValuePair<int,string>kv in d) //키랑 밸류 둘다받아오는 함수 KeyValuePair
            {
                Console.WriteLine(kv);
            }
            d.Remove(2);
            Console.WriteLine("==================");
            foreach (KeyValuePair<int, string> kv in d) 
            {
                Console.WriteLine(kv);
            }
            Console.WriteLine("==================");
            Console.WriteLine(d[1]);
            Console.WriteLine(d.Count);
            Console.WriteLine("==================");
            Dictionary<string, string> d2 = new Dictionary<string, string>();
            d2.Add("name", "kkk");
            Console.WriteLine(d2["name"]);  //배열의 인덱스와는 다름..지정하는 키값임..
            Console.WriteLine(d2["age"]);
        }
    }
}
