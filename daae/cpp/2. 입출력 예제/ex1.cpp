#include <iostream>
/*
using namespace std;       //�Լ����� namespace���Ÿ� �Լ����� �����־����!
void simon(int n);
void main()
{

	int count;

	simon(3);
	cout<<"������ ���ÿ�";

	cin>>count;
	simon(count);
	cout<<"��"<<endl;
}
void simon(int n)
{
	cout<<"simon ��, �߰����� "<<n<<"�� �ε����"<<endl;
}
*/
//--------------------------------------------------------------------
int stonetolb(int stone)
{
	return 14*stone;
}
void main()
{
	using namespace std;
	int stone;

	cout<<"ü���� �������� �Է�";
	cin>>stone;

	int pounds=stonetolb(stone);
	cout<< stone<<"������ ";
	cout<< pounds<<"�Ŀ�� �Դϴ�"<<endl;

}
