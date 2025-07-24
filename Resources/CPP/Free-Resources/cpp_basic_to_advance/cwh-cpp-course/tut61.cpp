#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream hout("sample61.txt");
    int n;
    cout << "Enter the number of students : " << endl;
    cin >> n;
    string s = "STUDENT LIST";
    hout << s << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        string name;
        cout << "STUDENT " << (i + 1) << endl;
        cout << "Enter your name : " << endl;
        cin >> name;
        hout << (i + 1) << ". " << name << endl;
    }
    hout.close();

    ifstream hin("sample61.txt");
    string content;
    while (hin.eof() == 0)
    {
        getline(hin, content);
        cout << content << endl;
    }
    hin.close();

    return 0;
}