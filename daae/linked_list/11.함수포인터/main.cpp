s//void f1();
//void (*p)int=f1; 함수 포인터....

#include <iostream>
using namespace std;

void f1(char *str){
	cout<<"f1 : "<<str;
}
void f2(char *str){
	cout<<"f2 : "<<str;
}
void f3(char *str){
	cout<<"f3 : "<<str;
}
void f4(char *str){
	cout<<"f4 : "<<str;
}

void main()
{
	int check;
	void (*p[4])(char *) = {f1,f2,f3,f4};		//함수의 이름은 함수의 주소값...함수 포인터 타입은 함수의 타입에 맞춰야함..
//	p("aaa\n");									//스레드는 함수로 등록?...

	cout<<"숫자 입력 : (0~3) "<<endl;		
	cin>>check;

	switch(check)								//if보다 스위치가 빨라..이벤트가 엄청많을 땐 look up table (=함수 포인터의 배열)이 더빨라
	{
	case 0 : p[0]("aaa");						//시그널..프로세스간에 통신.. 
		break;
	case 1 : p[1]("bbb"); 
		break;
	case 2 : p[2]("ccc"); 
		break;
	case 3 : p[3]("ddd"); 
		break;
	default :break;
	}



//	cout<<endl;
//	f1("111");
}