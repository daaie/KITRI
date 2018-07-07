#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream ofs("a.txt");		//쓰기모드
	string a = "asdf";
	ofs << a << endl;
	ofs.close();

	ifstream ifs("a.txt");		//읽기모드
	string b = "";
	ifs >> b;
	cout << b << endl;
	ifs.close();
}