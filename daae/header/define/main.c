#include <stdio.h>
#define PI 3.141592						//대소문자 구별함!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define str "원의 면적을 계산했습니다\n"
#define END_MSG printf ("프로그램이 종료되었습니다\n")

void main()
{
	printf ("반지름이 10인 원의 면적은 : %.5lf", 10*10*PI);
	printf (str);
	END_MSG;
}


//예) 포트이름을 디파인해주면 나중에 수정할때 편하당..포트를 바꿔도 편하당..