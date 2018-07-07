#include <stdio.h>

void main()
{
	char a[20];
	FILE *rfp;       //FILE *맘대로

	fopen_s(&rfp,"c:\\users\\KITRI\\desktop\\data1.txt","r");   //주소..?
	//rfp=fopen("c:\\users\\KITRI\\desktop\\data1.txt","r");


	fgets(a,strlen(a),rfp);
	printf ("len=%d\n",strlen(a));

	printf ("파일에서 읽은 문자열:");
	puts(a);

	fclose(rfp);
}