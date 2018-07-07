using System;
using System.Collections.Generic;
using System.Text;

namespace _.학생예제
{
    class Student
    {
        public string name;
        public int number;
        public int korean, math, english, total;
        public float avg;

        public void readvalue(int i)
        {
            Console.WriteLine("======={0}번 학생=======",i);
            Console.Write("이름? : ");
            name = Console.ReadLine();
            Console.Write("학번? : ");
            number = Int32.Parse(Console.ReadLine());
            Console.Write("국어? : ");
            korean = Int32.Parse(Console.ReadLine());
            Console.Write("수학? : ");
            math = Int32.Parse(Console.ReadLine());
            Console.Write("영어? : ");
            english = Int32.Parse(Console.ReadLine());
        }
        public void calc()
        {
            total = korean + math + english;
            avg = total / 3;
        }
        public void print()
        {
            Console.WriteLine("=========================");
            Console.WriteLine("이름 = {0}", name);
            Console.WriteLine("번호 = {0}", number);
            Console.WriteLine("국어 = {0}", korean);
            Console.WriteLine("수학 = {0}", math);
            Console.WriteLine("영어 = {0}", english);
            Console.WriteLine("총점 = {0}", total);
            Console.WriteLine("평균 = {0}", avg);
        }

    }
    class StudentProcess
    {
        public Student[] arr;
        public int cnt;
        public StudentProcess()
        {
            arr = new Student[3];
            cnt = 0;
            //배열다쓰고 더 넣으면 컬렉션...메모리 계속늘어남
        }
        public void insert(Student s)//객체 주소값 받는것과같음..
        {
            arr[cnt++] = s;
        }
        public void printAll()
        {
            foreach (Student s in arr)
            s.print();

        }
        public void sort()
        {
            Student temp;
            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = i; j < arr.Length; j++)
                {
                    if (arr[i].total < arr[j].total)
                    {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }

        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            StudentProcess sp = new StudentProcess();

            for (int i = 0; i < sp.arr.Length; i++)
            {
                sp.insert(new Student());
                sp.arr[i].readvalue(sp.cnt);
                sp.arr[i].calc();
            }
            sp.sort();
            sp.printAll();
        }
    }
}