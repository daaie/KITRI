#include <iostream>
using namespace std;
ostream& operator<<(ostream &os,struct node *s);

struct node{
char name[10];
char tel[20];
char address[40];
struct node *next;
};

class Linked
{

public :

struct node *head;
struct node *tail;
struct node *bmp;

	Linked();
	~Linked();
	void addnode();
	void print();
	struct node* search (const char *name);
};