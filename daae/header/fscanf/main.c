#include <stdio.h>

void main()
{
	FILE *rfp;
	int hap=0;
	int i,in;

	rfp=fopen("c:\\users\\KITRI\\desktop\\data2.txt","r");
	
	for (i=0;i<5;i++)
	{
		fscanf_s(rfp,"%d",&in);       //주소..?
		hap+=in;
	}
	printf ("합계 = %d\n",hap);
	fclose(rfp);

}
//--------------------------------------------------------------

