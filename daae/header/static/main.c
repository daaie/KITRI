#include <stdio.h>

void myfunc();

void main()
{
	myfunc();
	myfunc();
}

void myfunc()
{
	static int a=0; //�Լ��� ���������� ��������� �ٸ�....?...���ο����� ���ȵ�..
//	a=0;			//static int a=0�� ������ (�Ȱ��� ����) �ʱ�ȭ ���ϴµ�....������ �� ��...	
	a=a+100;
	printf ("a�� : %d",a);
}
