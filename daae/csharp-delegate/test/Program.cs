using System;
using System.Collections.Generic;
using System.Text;
//c# ������ delegate�� c������ �Լ�������
//c���� ������ �迭���� �� �Լ��� �ּҰ��� �����ϰ� �ִٰ� �̺�Ʈ�� �߻��ϸ� �ּҰ����� �Լ� ��ȣ��...
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
            //�븮�� ��ü ����
            int x=0,y=0;
            del A;
            A = new del(test1);
            x=A();
            Console.WriteLine("x={0}",x);
            del B = delegate()
            {
                Console.WriteLine("==========");
                Console.WriteLine("�͸�");
                return 1;
            };
            y=B();
            Console.WriteLine("y={0}", y);
        }
    }
}
//��ưŬ���̳� ��ǹ߻� - �̺�Ʈ �߻� �Ҷ� �ڵ鷯..
//��ư Ŭ�� ->�ڵ鷯�� �������ϰ�� ���������� �Լ��� ȣ��Ǿ���..->��������Ʈ ��������..
//