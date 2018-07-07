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
            //Ű�� ���̶� �ΰ� �����������
            Dictionary<int, string> d = new Dictionary<int, string>();
            //Ű���� ������ ���ο��� �ؽ��ڵ�... ������ ����
            //�ؽ��ڵ带 �������� values(string)�� ã��
            //�����˻��� ����..

            d.Add(1,"aaa");
            d.Add(2,"bbb");
            d.Add(3,"ccc");
            foreach (KeyValuePair<int,string>kv in d) //Ű�� ��� �Ѵٹ޾ƿ��� �Լ� KeyValuePair
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
            Console.WriteLine(d2["name"]);  //�迭�� �ε����ʹ� �ٸ�..�����ϴ� Ű����..
            Console.WriteLine(d2["age"]);
        }
    }
}
