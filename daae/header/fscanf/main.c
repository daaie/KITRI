#include <stdio.h>

void main()
{
	FILE *rfp;
	int hap=0;
	int i,in;

	rfp=fopen("c:\\users\\KITRI\\desktop\\data2.txt","r");
	
	for (i=0;i<5;i++)
	{
		fscanf_s(rfp,"%d",&in);       //�ּ�..?
		hap+=in;
	}
	printf ("�հ� = %d\n",hap);
	fclose(rfp);

}
//--------------------------------------------------------------

