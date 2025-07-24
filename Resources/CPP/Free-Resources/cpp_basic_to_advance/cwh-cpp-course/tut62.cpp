#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ofstream out;
    out.open("sample62.txt");
    out << "This is me" << endl;
    out << "This is also me" << endl;
    out.close();

    ifstream in;
    string st;
    in.open("sample62.txt");
    // getline(in, st);
    // cout << st << endl;
    // getline(in, st);
    // cout << st << endl;
    while (in.eof() == 0)
    {
        getline(in, st);
        cout << st << endl;
    }
    in.close();
    return 0;
}