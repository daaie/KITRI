#include <iostream>
using namespace std;
class Subject
{
   int id;
   int open;
   char name[10];
   Subject *next;
   Subject *head;
   Subject *tail;
};


class SubjectInfo 
{
   //char *prof;
   char day[10];
   int classRoom;
   int classTime;
   int capacity;
   int now_student;
};