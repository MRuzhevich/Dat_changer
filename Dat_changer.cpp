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

struct twoVectors {
	vector<float> vecOfColumnFirst;
	vector<float> vecOfColumnSecond;
	
};



twoVectors dataFromColumn() {
	char buff[100];
	ifstream rfile("test1.dat");
	string first = "";
	string second = "";
	vector<float> vecOfColumnFirst;
	vector<float> vecOfColumnSecond;
	if (rfile.is_open()) {
		while (rfile.getline(buff, 100)) {
			string strbuff(buff);
			vector<string> line = splitString(strbuff);
			if (line.size() >= 1) {
				first = line[0];
				second = line[1];
				float nfirst = stof(first);
				float nsecond = stof(second);
				vecOfColumnFirst.push_back(nfirst);
				vecOfColumnSecond.push_back(nsecond);
			}
		}
	} 
	twoVectors twoVectorsOfColums = { vecOfColumnFirst, vecOfColumnSecond };
	return twoVectorsOfColums; 
	;
}

int main()
{
	float minsecond;
	int k = 0;
	char buff[100];
	ifstream rfile("test1.dat");
	
	ofstream wfile("test_new.dat");

	twoVectors twoVectorsOfColums = dataFromColumn();
	vector<float> firstColumn = twoVectorsOfColums.vecOfColumnFirst;
	auto minFromFCol = *min_element(firstColumn.begin(), firstColumn.end());
	vector<float> secondColumn = twoVectorsOfColums.vecOfColumnSecond;
	auto minFromSCol = *min_element(secondColumn.begin(), secondColumn.end());


	if (rfile.is_open()) {
		while (rfile.getline(buff, 100)) {
			string first = "";
			string second = "";
			float intens, energy;
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


		

						//intens = nsecond - minsecond;

						cout << nfirst << '\t' << nsecond << endl;

						
					


					}
					catch (const exception& e) {
						cout << "Ошибка преобразования строки в число: " << e.what() << endl;
					}
				}
				//else { cout << "<2" << endl; }
			}
			else { cout << "File not opened" << endl; }
		}
	}
	else { cout << "File not opened" << endl; }
	wfile.close();

	system("pause>0");
}