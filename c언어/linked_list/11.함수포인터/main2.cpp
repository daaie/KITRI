
#include <iostream>
using namespace std;

struct Test{
	char d;
	int a;
	char b;
	int c;
};


void f1(char *str){
	cout<<"f1 : "<<str;
}

void f2(int *p, int size){
	int i;
	for (i=0;i<size;i++){
		cout<<"f2 : "<<p[i];
	}
}

void f3(void (*p)(char*),char *str){
	p(str);
}
//
void f4(struct Test *t){
	cout<<t->a<<endl;
	cout<<t->b<<endl;
	cout<<t->c<<endl;
	cout<<t->d<<endl;

}
//void f4(struct Test t){
//	cout<<t.a<<endl;
//	cout<<t.b<<endl;
//	cout<<t.c<<endl;
//	cout<<t.d<<endl;
//
//}
//


void main()
{
	int check;
	//void (*p[4])(char *) = {f1,f2,f3,f4};		
	int arr[]={1,2,3};

	struct Test t;
	t.a=1;
	t.b='x';
	t.c=2;
	t.d='y';

	cout<<"qqq"<<sizeof(struct Test)<<endl;	//인트 2개 캐릭터 2개라도 16바이트 할당받음 t.a / t.c 는 4바이트 t.b / t.d 1바이트
											//변수 형의 배수에만 저장하게 되있음 ...인트는 4의 배수만 저장함.
											//int a, char b, char b, int d 면 12바이트...캐릭터가 암떄나 들어가니까..
											//순서만 바꿔도 메모리 절약./..



	f2(arr,3);
	f3(f1,"aaa");
	f4(&t);
	
	//cout<<"숫자 입력 : (0~3) "<<endl;		
	//cin>>check;

	//switch(check)								
	//{
	//case 0 : p[0]("aaa");						
	//	break;
	//case 1 : p[1](p,3); 
	//	break;
	//case 2 : p[2](p[1],"asdf");
	//	break;
	//case 3 : p[3]
	//	break;
	//default :break;
	//}

}