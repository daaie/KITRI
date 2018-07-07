
class Person
{
	char *name;
	int age;

public :
	Person ();
	void Person::setinfo(char *name, int a);
	void getinfo();
	bool operator<(Person &p);
	Person& operator=(Person &p);
};
