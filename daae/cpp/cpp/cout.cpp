#include <iostream>							//����� h�� ����. input output...
int main(void)
{
	int num=20;
											//cout -> console out..
	std::cout<<"hello world!"<<std::endl;   //std::endl �� ��� ����
	std::cout<<"hello "<<"world"<<std::endl;
	std::cout<<num<<' '<<'A';				//���������� ���ʿ�
	std::cout<<' '<<3.14<<std::endl;
	std::cout<<"test"<<std::endl<<"test2";
	std::cout<<std::endl;					//endl�� cout ���� �ȉ�..
	printf ("num=%d",num);
}
