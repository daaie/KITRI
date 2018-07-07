#include <stdio.h>

void myfunc();

void main()
{
	myfunc();
	myfunc();
}

void myfunc()
{
	static int a=0; //함수내 선언이지만 저장공간이 다름....?...메인에서는 사용안됨..
//	a=0;			//static int a=0만 있으면 (똑같은 선언) 초기화 안하는데....대입은 또 함...	
	a=a+100;
	printf ("a는 : %d",a);
}
