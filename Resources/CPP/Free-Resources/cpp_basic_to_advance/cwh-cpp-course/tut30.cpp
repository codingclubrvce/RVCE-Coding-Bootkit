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

    // parameterized constructed
    complex(int x, int y)
    {
        a = x;
        b = y;
    }
};

int main()
{
    complex c(4, 5);
    c.printnumber();
    return 0;
}
