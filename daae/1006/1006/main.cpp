#include <iostream>
using namespace std;
//구조체 안에는 1인분!
struct student
{
	int id;
	float grade;
	int gender;
};

void main()
{
	struct student student;

	cout<<"학번을 입력하세요\n";
	cin>>student.id;

	cout<<"성적을 입력하세요\n";
	cin>>student.grade;

	cout<<"gender? (남성 1 여성 2)\n";
	cin>>student.gender;

	cout<<"\n\n";
	cout<<"id : "<<student.id<<endl;

	cout.setf(ios::showpoint);		//소숫점표기해주겠다.
	cout.precision(2);				//2자리 표기 ...cout이라는 구조체?
	cout<<"성적은 : "<<(float)student.grade<<endl;

	cout<<"성별은 : "<<(student.gender==1?"남자":"여자")<<endl;
	cout<<"입니다"<<endl;
	
}