//inline - define�� ����� �ӵ�?
//�Լ��� ȣ��� ���Ϳ� �ð��� ���� �ɸ�.. �׷��� inline��
//define > inline > �Լ�
#include <iostream>
using namespace std;
inline int inc(int x)
{
	return x+1;
}
int main(int argc, char* argv[])
{
	int i;
	cout<<"���� : ";
	cin>>i;
	cout<<inc(i)<<endl;
	return 0;
}
