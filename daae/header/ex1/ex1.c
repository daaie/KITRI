//구구단

#include <stdio.h>
void main()
{
	int i,j,k;
	FILE *gugu;
	gugu=fopen("c:\\users\\KITRI\\desktop\\gugu.txt","w");



	for(i=2;i<=9;i++)
		fprintf (gugu," #제 %d단#\   ",i);
		fprintf (gugu,"\n\n");

	for (i=1;i<=9;i++)
	{
		for (j=2;j<=9;j++)
		{
			fprintf(gugu,"%d x %d = %2d  ",j,i,i*j);
		}
			fprintf (gugu,"\n");

	}

	fclose(gugu);
}