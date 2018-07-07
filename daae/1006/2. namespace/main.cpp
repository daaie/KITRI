#include <iostream>
using namespace std;
namespace Elementary
{
	struct sudent
	{
		int id;
		int age;
	};
}

namespace University
{
	struct student
	{
		int id;
		float grade;
	};
}

void main()
{
	struct Elementary::sudent eleStudent;

	cout<<"Enter elementary student's id\n";
	cin >>eleStudent.id;
	cout<<"Enter Elementary student's age\n";
	cin >>eleStudent.age;

	struct University::student uniStudent;

	cout<<"Enter University student's id\n";
	cin >>uniStudent.id;
	cout<<"Enter University student's grade\n";
	cin >>uniStudent.grade;

	cout<<"elementary student's"<<endl;
	cout<<"\t id="<<eleStudent.id<<endl;
	cout<<"\t AGE="<<eleStudent.age<<endl;
	cout<<"university student's"<<endl;
	cout<<"\t id="<<uniStudent.id<<endl;
	cout<<"\t Grade="<<uniStudent.grade<<endl;
}




