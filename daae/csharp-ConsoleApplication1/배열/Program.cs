using System;
using System.Collections.Generic;
using System.Text;

namespace 배열
{
    class Program
    {
        static void Main(string[] args)
        {
            int i;
            int[] a ={ 1, 2, 3, 4 };
            int[] b = new int[] { 1, 2, 3 };
            int[] c = new int[2];
            c[0] = 1;
            c[1] = 2;
            for (i = 0; i < a.Length; i++)
                Console.WriteLine("a[{0}]={1}", i, a[i]);
            for (i = 0; i < b.Length; i++)
                Console.WriteLine("b[{0}]={1}", i, b[i]);
            for (i = 0; i < c.Length; i++)
                Console.WriteLine("c[{0}]={1}", i, c[i]);
            //length는 방의 개수
            foreach (int val in a)
                Console.WriteLine(val);
            //a의 값을 앞부터 하나씩 읽어옴
        }
    }
}
