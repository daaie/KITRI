#include <stdio.h>

void main()
{
	char a[20];
	FILE *rfp;       //FILE *�����

	fopen_s(&rfp,"c:\\users\\KITRI\\desktop\\data1.txt","r");   //�ּ�..?
	//rfp=fopen("c:\\users\\KITRI\\desktop\\data1.txt","r");


	fgets(a,strlen(a),rfp);
	printf ("len=%d\n",strlen(a));

	printf ("���Ͽ��� ���� ���ڿ�:");
	puts(a);

	fclose(rfp);
}