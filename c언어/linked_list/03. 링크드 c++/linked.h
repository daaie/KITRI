#include <iostream>
class Linked
{
	struct node{
		char name[10];
		char tel[20];
		char address[40];
		struct node *next;
	};
	struct node *head;
	struct node *tail;
	struct node *bmp;
	struct node *bmp2;
public :
	Linked();
	~Linked();
	void addnode();
	void searchnode();
	void changenode();
	void printnode();
	void delnode();
	//void ending();
};

				