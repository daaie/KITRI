using System;
using System.Collections.Generic;
//collections ���ӽ����̽� ť,��Ʈ,�迭,�ؽ����̺�
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args) //static -> ��ü�� �������� �ʰ� ���ٰ����ϴϱ�..������ �׷��� static
        {                               //Ÿ��[] ->�迭Ÿ��..��Ʈ�� �迭�� ���⼱.
                                        //�迭�� ����Ҹ޸� �Ҵ�������� new�����..�굵 ������..
            string name = "aaa";
            int age ;
            float x ;
            Console.Write("name:");
            name = Console.ReadLine(); //��������� ������ ���ڿ�
            age = Int32.Parse(Console.ReadLine());
                                       //Int32 -> �⺻�� ��Ʈ���� Ŭ����Ÿ��
            x = Single.Parse(Console.ReadLine());
            Console.WriteLine("name={0},age={1},x={2}",name,age,x);
                                       //�߰�ȣ {index} ->������ ����
                                       //�ְܼ�ü�� WriteLine�� static�̶�� �Ҹ�..
                                       //Write�� WriteLine�� ���̴� ���๮��
        }
    }
}
//�⺻��..
//sbyte(1) �������� ����Ʈ
//ubyte(1) ��������� ����Ʈ
//short(2) , ushort(2)
//int(4), uint(4)
//long(8), ulong(8)
//char(2) ->�����ڵ�� �ι���Ʈ
//bool(1)
//float(4)
//double(8)
//enum->null�� ���

//��ü��
//string, object
//objectŬ������ C#���� ���Ǵ� ��� Ŭ������ ������..��� Ŭ������ object�� ��ӹ���..