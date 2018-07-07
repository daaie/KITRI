#include <iostream>
using namespace std;
class snake
{
	friend int attack(snake &obj);
public : 

};

int attack(snake &obj)
{
	return 1;
}
void main()
{
	snake cobra;
	cobra.attack();
}
