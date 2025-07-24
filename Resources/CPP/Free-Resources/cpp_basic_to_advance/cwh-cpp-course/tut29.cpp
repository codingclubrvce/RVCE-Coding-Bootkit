#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    void printnumber()
    {
        cout << a << "+" << b << "i" << endl;
    }
    complex(void)
    {
        a = 100;
        b = 90;
    }
};

int main()
{
    complex c;
    c.printnumber();
    return 0;
}