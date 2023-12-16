#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> splitString(string spacestr) {
	string nstr = "";
	vector<string> words;
	for (auto x : spacestr) {
		if (x == ' ') {
			if (!nstr.empty()) {
				words.push_back(nstr);
				nstr = "";
			}
		}
		else {
			nstr += x;
		}
	}

	if (!nstr.empty()) {
		words.push_back(nstr);
	}

	return words;
}


int main()
{
	char buff[50];
	ifstream rfile("test1.dat");
	ofstream wfile("test_new.dat");

	while (rfile.getline(buff, 50)) {
		string first = "";
		string second = "";
		wfile << buff << endl;
		string str(buff);
		//cout << str << endl;

		vector <string> vec = splitString(str);

		first = vec[0];
		second = vec[1];

		int nfirst = stoi(first);
		int nsecond = stoi(second);

		cout << nfirst << endl;
		cout << nsecond << endl;
	}

	wfile.close();

	system("pause>0");
}