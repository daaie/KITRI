#include <iostream>

void f1();

int a;				//전역 변수, 초기화도 안함 => bss영역 

int main()			//stack -> main..현재 main스택이 활성화

{
	//int a=1;		//stack->a=1;


	{				//블록...스택의 main내부에 블록을 침...블록 활성화
		//int a=10;	//만약 a=10;이 없으면 a=1, a=1도 없으면 전역변수(정적) a에 접근
		int b=20;
		printf("a=%d, b=%d\n",a,b);
	}



		//printf("a=%d, b=%d\n",a,b);	//a=1이고 b는 블록이 끝나고 풀려서 에러
		f1();
}

void f1()
{
	printf("a=%d", a);		//활성화 스택(f1)에서 a찾고 -> 전역 a
}
