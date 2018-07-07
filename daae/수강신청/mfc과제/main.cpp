#include <iostream>
#include "people.h"
using namespace std;

void main()
{
   while (1)
   {
      int input = 0;
      cout << "로그인 할 직책" << endl;
      cout << "1. 교직원" << endl;
      cout << "2. 교수" << endl;
      cout << "3. 학생" << endl;
      cin >> input;
      People p;
	  Staff sf;	
	  Professor prof;		
      switch (input)
      {
      case 1: sf.addSubject();
         break;
      case 2: prof.printSubject();
         break;
      case 3: p.job = 0;
         p.addPeople(&p);
         break;
      default: break;
      }

   }
}