#include <iostream>

using namespace std;

class Test
{
public :
	int x;
	static int y;

};
int Test::y=10;
int main()
{
	cout<<Test::y;		//����ƽ �ɹ��� ��ü �������ϰ� �׳� ��δ�..�ű�
	return 0;			//���� ������ �޸� Test�� ���� ����..
}
