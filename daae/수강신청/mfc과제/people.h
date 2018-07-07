#include <iostream>
#include "info.h"
using namespace std;
class People
{
public:
   char name[10];
   int SubId;
   bool job;         //1 = 교수 , 0= 학생
   void addPeople(People *p);
   People()
   {
	   int SubId=0;
   }
   People *next;
   People *head;
   People *tail;
};

void People::addPeople(People *p)
{
   int flag = 1;
   while (flag)
   {
      cout << "이름 입력" << endl;
      cin >> p->name;

      if (head == NULL)
      {
         head = p;
      }
      else
      {
         tail->next = p;
      }
      tail = p;
      tail->next = NULL;

      cout << "그만하려면 0입력" << endl;
      cout << "입력 : ";
      cin >> flag;
   }
}


class Professor
{
public:
   void printSubject()
   {
      struct Subject *bmp;
      bmp = head;

      while (bmp != NULL)
      {
         cout << "과목 번호 : " << bmp->id << endl;
         cout << "과목 이름 : " << bmp->name << endl;
         if (bmp->open == 0)   cout << "개설 안됨" << endl;
         if (!bmp->open) cout << "개설 됨" << endl << endl;
         bmp = bmp->next;
      }

   }
};


class Staff
{
public:
   void addSubject()
   {
      int flag = 1;
      while (flag)
      {
         struct Subject *bmp;

         bmp = new Subject;
         cout << "추가할 과목 번호" << endl;
         cin >> bmp->id;
         cout << "추가할 과목 이름" << endl;
		 cin>>bmp->name;

         if (head == NULL)
         {
            head = bmp;
         }
         else
         {
            tail->next = bmp;
         }
         tail = bmp;
         tail->next = NULL;

         cout << "그만하려면 0입력" << endl;
         cout << "입력 : ";
         scanf("%d",&flag);
      }
   }
};