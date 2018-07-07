//func.c와 func.h는 한세트
//같은 폴더 안의 헤더는 "" ,프로그램 내부헤더에는 <>임...

//#include "func.h" 
//#include <stdio.h>    //main에서 선언했으니까 굳이 선언안해도 됨..

void func(int num)
{
	printf ("%d\n",num);
}
