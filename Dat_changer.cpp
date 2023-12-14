#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char buff[50];
    ifstream rfile("test1.dat");
    ofstream wfile("test_new.dat");

    while (rfile.getline(buff, 50)) {
        cout << buff << endl;
        wfile << buff << endl;

    }

    wfile.close();

    system("pause>0");
}