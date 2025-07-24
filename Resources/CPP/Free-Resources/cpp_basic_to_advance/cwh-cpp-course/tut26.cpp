#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    friend complex sumcomplex(complex o1, complex o2);
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

complex sumcomplex(complex o1, complex o2)
{
    complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
}

int main()
{
    complex c1, c2, c3;

    c1.setNumber(5, 2);
    c2.setNumber(1, 4);

    c1.printNumber();
    c2.printNumber();

    c3 = sumcomplex(c1, c2);
    c3.printNumber();
    return 0;
}