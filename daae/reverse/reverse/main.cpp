#include <stdio.h>
#include <string.h>

void main()
{
	char *src="HELLO";
	char *end=NULL;
	char temp;

	
	end=src+strlen(src)-1;

	while(src<end)
	{
		temp=*src;
		*src=*end;
		*end=temp;
		src++;
		end--;
	}
	//printf("%s",src);

}
