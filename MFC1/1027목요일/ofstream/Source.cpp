#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream ofs("a.txt");		//������
	string a = "asdf";
	ofs << a << endl;
	ofs.close();

	ifstream ifs("a.txt");		//�б���
	string b = "";
	ifs >> b;
	cout << b << endl;
	ifs.close();
}