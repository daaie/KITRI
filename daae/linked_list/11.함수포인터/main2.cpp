
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

	cout<<"qqq"<<sizeof(struct Test)<<endl;	//��Ʈ 2�� ĳ���� 2���� 16����Ʈ �Ҵ���� t.a / t.c �� 4����Ʈ t.b / t.d 1����Ʈ
											//���� ���� ������� �����ϰ� ������ ...��Ʈ�� 4�� ����� ������.
											//int a, char b, char b, int d �� 12����Ʈ...ĳ���Ͱ� �ϋ��� ���ϱ�..
											//������ �ٲ㵵 �޸� ����./..



	f2(arr,3);
	f3(f1,"aaa");
	f4(&t);
	
	//cout<<"���� �Է� : (0~3) "<<endl;		
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