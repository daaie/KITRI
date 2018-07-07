#include <iostream>
#include "info.h"
using namespace std;
class People
{
public:
   char name[10];
   int SubId;
   bool job;         //1 = ���� , 0= �л�
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
      cout << "�̸� �Է�" << endl;
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

      cout << "�׸��Ϸ��� 0�Է�" << endl;
      cout << "�Է� : ";
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
         cout << "���� ��ȣ : " << bmp->id << endl;
         cout << "���� �̸� : " << bmp->name << endl;
         if (bmp->open == 0)   cout << "���� �ȵ�" << endl;
         if (!bmp->open) cout << "���� ��" << endl << endl;
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
         cout << "�߰��� ���� ��ȣ" << endl;
         cin >> bmp->id;
         cout << "�߰��� ���� �̸�" << endl;
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

         cout << "�׸��Ϸ��� 0�Է�" << endl;
         cout << "�Է� : ";
         scanf("%d",&flag);
      }
   }
};