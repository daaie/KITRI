#include <iostream>

void f1();

int a;				//���� ����, �ʱ�ȭ�� ���� => bss���� 

int main()			//stack -> main..���� main������ Ȱ��ȭ

{
	//int a=1;		//stack->a=1;


	{				//���...������ main���ο� ����� ħ...��� Ȱ��ȭ
		//int a=10;	//���� a=10;�� ������ a=1, a=1�� ������ ��������(����) a�� ����
		int b=20;
		printf("a=%d, b=%d\n",a,b);
	}



		//printf("a=%d, b=%d\n",a,b);	//a=1�̰� b�� ����� ������ Ǯ���� ����
		f1();
}

void f1()
{
	printf("a=%d", a);		//Ȱ��ȭ ����(f1)���� aã�� -> ���� a
}
