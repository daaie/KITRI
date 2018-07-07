#include <stdio.h>
void main()
{
	FILE *wfp;
	int hap=0;
	int in,i;

	fopen_s(&wfp,"c:\\users\\KITRI\\desktop\\data4.txt","w");
	for (i=0;i<5;i++)
	{
		printf ("숫자 %d",i+1);
		scanf ("%d",&in);
		hap+=in;
	}

	fprintf (wfp,"합계 = %d\n",hap);
	fclose(wfp);
}
