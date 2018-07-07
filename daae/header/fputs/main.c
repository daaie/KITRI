#include <stdio.h>
void main()
{
	int a[20];
	FILE *wfp;
	wfp=fopen("c:\\users\\KITRI\\desktop\\data2.txt","a"); //w= 있는 파일에 쓰면 다 덮어씀
														   //a=이어씀	

	printf ("문자열을 입력하세요\n");
	gets_s(a,20);
	fputs(a,wfp);

	fclose(wfp);
}