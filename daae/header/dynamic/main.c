//전역변수 - > 데이터영역
//외부 함수 내 선언 ->스택영역에서 생성, 함수 종료 후 소멸
//main 함수내 선언 ->스택영역
//main fun1 fun2 순으로 불러오면 fun2 fun1 main 순으로 소멸///
//동적 메모리는 힙에 저장..

#include <stdio.h>
/*
void main()
{
	int *pi;
	double *pd;

	pi=(int*)malloc(sizeof(int));

	if (pi==NULL)
	{
		printf ("#으로 메모리가 부족합니다\n");
		exit(1);	//종료..
	}
	pd=(double*)malloc(sizeof(double));

	*pi=10;
	*pd=3.4;

	printf ("정수형으로 사용 : %d\n",*pi);
	printf ("실수형으로 사용 : %lf\n",*pd);

	free(pi);					//보통 소스 내부에서 잠깐 메모리 잡을때 동적메모리 사용하므로...풀어주는게 필요함..
	free(pd);

}


*///------------------------------------------------------------------------------------------------------------------

void main()
{
	int *pi;
	int i,sum=0;

	pi=(int*)malloc(5*sizeof(int));   //힙영역에 int형 5개의 공간을 잡음..
	if (pi==NULL)
	{
		printf ("memory loss\n");
		exit(1);
	}

	printf ("5명의 나이를 입력하세요\n");
	for (i=0;i<5;i++)
	{
		scanf ("%d",&pi[i]);
		sum+=pi[i];
	}

	printf ("avg age=%.1lf",(sum/5.0));
	free(pi);
}
