#include <iostream>
using namespace std;

class A
{
public:
    int a, b;

    void getdata()
    {
        cout << "Enter the value of a and b :" << endl;
        cin >> a >> b;
    }
};

class B : public A
{
    int c;

public:
    void sum()
    {
        c = a + b;
        cout << "The sum of a and b is " << c << endl;
    }
};

int main()
{
    B obj;
    obj.getdata();
    obj.sum();

    return 0;
}