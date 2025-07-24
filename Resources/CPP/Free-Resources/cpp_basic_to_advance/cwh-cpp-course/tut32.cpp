#include <iostream>
using namespace std;

class Simple
{
    int data1;
    int data2;

public:
    Simple(int a, int b = 9)
    {
        data1 = a;
        data2 = b;
    }
    void printData();
};

void Simple ::printData()
{
    cout << "The value of data is " << data1 << " and " << data2 << endl;
}
int main()
{
    Simple s1(2, 5);
    s1.printData();

    Simple s2(8);
    s2.printData();

    return 0;
}