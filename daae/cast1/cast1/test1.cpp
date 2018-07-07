#include<iostream>
	struct b {
		 int id;
	};
int main()
{

	struct b *a[4];
	a[0]->id =1;

//	b *(a[4]);
//	b *(a)[4];

	printf("%d",a[0]);

	return 0;
}