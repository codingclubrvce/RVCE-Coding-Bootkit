#include <iostream>
#include <fstream>
using namespace std;

/*
The usefull classes for working with files in C++ are :
1. fstreambase --> base class
2. ifstream --> derived class
3. ofstream --> derived class
In order to work with files you will have to open it and there are primarily 2 ways of opening the file :
1. using the constructor
2. using the special member function open() of the class

*/
int main()
{
    string st1 = "Harry bhai";
    string st2;
    string st3;
    // opening files using constructor
    ofstream out("sample60.txt"); // write operation
    out << st1;

    // opening files using constructor
    ifstream in("sample60b.txt"); // read operation
    // in >> st2;
    getline(in, st2);
    cout << st2 << endl;
    getline(in, st2);
    cout << st2;

    return 0;
}