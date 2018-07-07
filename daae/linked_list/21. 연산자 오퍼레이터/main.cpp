#include <iostream>
#include "person.h"
using namespace std;

void main()
{
	char imsiName[10];
	int imsiAge;

	cout<<"이름을 입력 ";
	cin>>imsiName;
	cout<<"나이를 입력 ";
	cin>>imsiAge;

	Person p1;
	Person p2(imsiName, imsiAge);
	Person p3=p1;  //Person p3(p1); 같댱.. (초기화)
	
	//복사 생성자가 없으면 p3는 p1의 주소를 공유하게됨.

	cout<<"1번째 학생 "<<p1<<endl;
	cout<<"2번째 학생 "<<p2<<endl;
	cout<<"3번째 학생 "<<p3<<endl;

	p3.setName("!!!!!!!!!!!!");
	cout<<endl;
	cout<<"1번째 학생 "<<p1<<endl;
	cout<<"2번째 학생 "<<p2<<endl; 
	cout<<"3번째 학생 "<<p3<<endl;   //복사 생성자 덕분에 p1에 영향을 안준다.

	p2=p3;
	p3.setName("@@@@@@@@@@@@@");
	cout<<endl;
	cout<<"1번째 학생 "<<p1<<endl;
	cout<<"2번째 학생 "<<p2<<endl;
	cout<<"3번째 학생 "<<p3<<endl;

}
	