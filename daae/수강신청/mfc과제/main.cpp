#include <iostream>
#include "people.h"
using namespace std;

void main()
{
   while (1)
   {
      int input = 0;
      cout << "�α��� �� ��å" << endl;
      cout << "1. ������" << endl;
      cout << "2. ����" << endl;
      cout << "3. �л�" << endl;
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