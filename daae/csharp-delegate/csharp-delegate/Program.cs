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
        //�븮�� ����
        public delegate void del(string s);
        //�븮�ڷ� ȣ���� �Լ� - ��������Ʈ�� ������ �Լ�
        public static void test1(string str)
            //��ü ����� �����Ƽ� ����ƽ���� ����..
            //��������Ʈ �Լ��� ��ȯŸ�԰� �Ű������� ���ƾ���
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
            //�븮�� ��ü ����
            del A,B,C,D;
            A = new del(test1);
            B = new del(test2);
            C = new del(test3);
            //�븮�ڷ� �Լ�ȣ��
            D = A + B + C;
            D("ddd");
            Console.WriteLine("===========");
            D -=B;
            D("ddd");

            del E = delegate (string s)  //Ÿ���� ���������..void ���...
            {
                Console.WriteLine("�͸� �޼���");
                Console.WriteLine(s);
            };//�Լ��� �ѹ��� ���� �����ž�...�̸����� �޼��� Ÿ���� ���������

            E("asdf");
        }
    }
}
//=========��� ����===============
//��ưŬ���̳� ��ǹ߻� - �̺�Ʈ �߻� �Ҷ� �ڵ鷯..
//��ư Ŭ�� ->�ڵ鷯�� �������ϰ�� ���������� �Լ��� ȣ��Ǿ���..->��������Ʈ ��������..
