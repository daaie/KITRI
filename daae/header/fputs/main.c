#include <stdio.h>
void main()
{
	int a[20];
	FILE *wfp;
	wfp=fopen("c:\\users\\KITRI\\desktop\\data2.txt","a"); //w= �ִ� ���Ͽ� ���� �� ���
														   //a=�̾	

	printf ("���ڿ��� �Է��ϼ���\n");
	gets_s(a,20);
	fputs(a,wfp);

	fclose(wfp);
}