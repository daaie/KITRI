#include <iostream>
using namespace std;

class baeyul
{
public :
void nyu()
{
	int i=0,j=0;
	int size=0;
	int (*p)[3];   //�ѹ� ���� �� �� 12����Ʈ�� ��
	
	cout<<"size :";
	cin>>size;



/************************************************************************************************/	
	//p=(int(*)[3])malloc(sizeof(int)*size*3);	//ĳ����....��...
	p=new int[size][3];
/************************************************************************************************/	



	for (i=0;i<size;i++)
	{
		for (j=0;j<3;j++)
		{
			p[i][j]=(j+1)+i*3;
			printf("%3d",p[i][j]);
		}
		 cout<<endl;
	}

	delete p;
}
		
};

void main()
{
	baeyul b;
	b.nyu();
}
