#include <iostream>
class NUM
{
	//�ϰ͵� �Ⱦ��� private
private :
	int num;
	//num=5 private�� �ʱ�ȭ �Ҽ� ����...

public :

	void out();
	void in();

};

void main()
{
	NUM num;
//	num.num=5;
//	num.in();
	num.out();
}

void NUM::out() //�ڡڡڡڡڡڡڡڡ�NUM:: �����ָ� �ٱ��Լ��� ��...
{
	num=5; // �Ҽ� ����..
	printf (" num : %d\n",num);
}

void NUM::in()
{
	scanf("%d",&num);
}
