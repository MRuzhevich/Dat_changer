#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> splitString(string tabstr) {
	string nstr = "";
	vector<string> words;
	for (auto x : tabstr) {
		if (x == '\t') {
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
	char buff[100];
	ifstream rfile("test1.dat");
	ofstream wfile("test_new.dat");
	if (rfile.is_open()) {
		while (rfile.getline(buff, 100)) {
			string first = "";
			string second = "";
			if (wfile.is_open()) {
				wfile << buff << endl;
				string str(buff);
				

				vector <string> vec = splitString(str);
				if (vec.size() >= 1) {
					first = vec[0];
					second = vec[1];

					try {
						float nfirst = stof(first);
						float nsecond = stof(second);

						cout << nfirst << '\t' << nsecond << endl;
						
					}
					catch (const exception& e) {
						cout << "Ошибка преобразования строки в число: " << e.what() << endl;
					}
				}
				//else { cout << "<2" << endl; }
			} else { cout << "File not opened" << endl; }
		}
	}
	else { cout << "File not opened" << endl; }
	wfile.close();

	system("pause>0");
}