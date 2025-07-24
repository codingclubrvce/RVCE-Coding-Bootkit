#include <iostream>
using namespace std;

class complex;
class calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }
    int sumrealcomplex(complex c1, complex c2);
    int sumcompcomplex(complex c1, complex c2);
};

class complex
{
    int a, b;
    // individually declaring functioins as friends
    friend int calculator ::sumrealcomplex(complex c1, complex c2);
    friend int calculator ::sumcompcomplex(complex c1, complex c2);
    // declaring the entire class as friend
    friend class calculator;

public:
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

int calculator ::sumrealcomplex(complex c1, complex c2)
{
    return (c1.a + c2.a);
}

int calculator ::sumcompcomplex(complex c1, complex c2)
{
    return (c1.b + c2.b);
}

int main()
{
    complex c1, c2;

    c1.setNumber(5, 2);
    c2.setNumber(1, 4);

    c1.printNumber();
    c2.printNumber();
    calculator calc;
    cout << "Real part of c1 + c2 is " << calc.sumrealcomplex(c1, c2) << endl;
    cout << "Imaginary part of c1 + c2 is " << calc.sumcompcomplex(c1, c2) << endl;

    return 0;
}