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

        public void readvalue()
        {
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
            Console.WriteLine("name = {0}", name);
            Console.WriteLine("num = {0}", number);
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
            arr[cnt++]=s;
        }
        public void printfAll()
        {
            foreach (Student s in arr) 
            s.print();
            
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            StudentProcess sp = new StudentProcess();
            sp.insert(new Student());
            sp.insert(new Student());
            sp.insert(new Student());
            for (int i = 0; i < sp.arr.Length; i++)
            {
                sp.arr[i].readvalue();
                sp.arr[i].calc();
            }
            sp.printfAll();
            
            //int total_kor=0, total_mat=0, total_eng=0; 

            //Student[] s= new Student[3];

            //for(int i=0;i<3;i++)
            //{
            //    s[i] = new Student();
            //    Console.WriteLine("====={0}번째 학생===== ",i+1);
            //    s[i].readvalue();
            //    s[i].calc();
            //    s[i].print();

            //    total_kor += s[i].korean;
            //    total_mat += s[i].math;
            //    total_eng += s[i].english;
            //}
            //Console.WriteLine("============모든학생=============");
            //Console.WriteLine("국어 총점 : {0}, 수학 총점 : {1}, 영어 총점 : {2} ", total_kor, total_mat, total_eng);
            //Console.WriteLine("국어 평균 : {0}, 수학 평균 : {1}, 영어 평균 : {2} ", total_kor/3, total_mat/3, total_eng/3);
        }
    }
}
