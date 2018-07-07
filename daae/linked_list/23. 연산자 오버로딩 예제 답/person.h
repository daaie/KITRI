using namespace std;
class Person
{
	char *name;
	int age;

public :
	Person ();
	Person (char *n, int a);
	Person (const Person &p);
	Person::~Person();
	void setName(char *n);

	bool operator>(const Person &p){
		return age>p.age;}

	Person& operator=(const Person &p);

	friend std::ostream& operator<<(ostream &os, const Person &p);

};
