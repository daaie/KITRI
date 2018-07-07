using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            int value,cnt=0,i=0;
         
            Console.Write("value? : ");
            value = Int32.Parse(Console.ReadLine());

            while(value!=cnt)
            {
                cnt++;
                if (value % cnt == 0)
                {
                    i++;
                    Console.WriteLine("{0}번째 약수 : {1}", i, cnt);
                }
            }
        }
    }
}
