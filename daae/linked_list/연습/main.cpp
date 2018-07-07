#include <iostream>

int main()
{
	//char a;
	//a='x';
	//a=-10;
	//printf ("%d",a);
	//return 0;
	
	int a=-1;
	
	if(sizeof(int)>a)			//sizeof는 unsigned 이고, -1은 signed.... 비교하기 위해 자동형변환..더 큰 unsigned로
	printf("true");				//-1은 언사인드 되면 더커짐.. 0111 1111 1111 1111 이 2바이트의 마지막 인트값임..
								//사인드면 -1이 1111 1111 1111 1111 이 될텐데 언사인드니까 0111 1111 1111 1111 더하기 2의 16승 됨.

	else 
	{
		printf("false");		//false 임..
	}
								//언사인드다->확장된 부분 0...사인드면 1이나 0으로 부호에 맞게...-는 1.

	return 0;
}