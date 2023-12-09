#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char buff[50];
	ifstream rfile("test1.dat");

	/*rfile >> buff;
	cout << buff << endl;*/

	rfile.getline(buff, 50);
	//rfile.close();
	cout << buff << endl;


	system("pause>0");
}