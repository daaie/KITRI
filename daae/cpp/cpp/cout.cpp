#include <iostream>							//헤더에 h가 없음. input output...
int main(void)
{
	int num=20;
											//cout -> console out..
	std::cout<<"hello world!"<<std::endl;   //std::endl 은 출력 개행
	std::cout<<"hello "<<"world"<<std::endl;
	std::cout<<num<<' '<<'A';				//서식지정이 불필요
	std::cout<<' '<<3.14<<std::endl;
	std::cout<<"test"<<std::endl<<"test2";
	std::cout<<std::endl;					//endl은 cout 없이 안됌..
	printf ("num=%d",num);
}
