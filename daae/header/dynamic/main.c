//�������� - > �����Ϳ���
//�ܺ� �Լ� �� ���� ->���ÿ������� ����, �Լ� ���� �� �Ҹ�
//main �Լ��� ���� ->���ÿ���
//main fun1 fun2 ������ �ҷ����� fun2 fun1 main ������ �Ҹ�///
//���� �޸𸮴� ���� ����..

#include <stdio.h>
/*
void main()
{
	int *pi;
	double *pd;

	pi=(int*)malloc(sizeof(int));

	if (pi==NULL)
	{
		printf ("#���� �޸𸮰� �����մϴ�\n");
		exit(1);	//����..
	}
	pd=(double*)malloc(sizeof(double));

	*pi=10;
	*pd=3.4;

	printf ("���������� ��� : %d\n",*pi);
	printf ("�Ǽ������� ��� : %lf\n",*pd);

	free(pi);					//���� �ҽ� ���ο��� ��� �޸� ������ �����޸� ����ϹǷ�...Ǯ���ִ°� �ʿ���..
	free(pd);

}


*///------------------------------------------------------------------------------------------------------------------

void main()
{
	int *pi;
	int i,sum=0;

	pi=(int*)malloc(5*sizeof(int));   //�������� int�� 5���� ������ ����..
	if (pi==NULL)
	{
		printf ("memory loss\n");
		exit(1);
	}

	printf ("5���� ���̸� �Է��ϼ���\n");
	for (i=0;i<5;i++)
	{
		scanf ("%d",&pi[i]);
		sum+=pi[i];
	}

	printf ("avg age=%.1lf",(sum/5.0));
	free(pi);
}
