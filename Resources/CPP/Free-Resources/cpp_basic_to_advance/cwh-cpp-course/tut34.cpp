#include <iostream>
using namespace std;

class Number
{
    int a;

public:
    Number()
    {
        a = 0;
    }
    Number(int num)
    {
        a = num;
    }
    // copy constructor - when no copy constructor is found the compiler supplies its own constructor
    Number(Number &obj)
    {
        cout << "Copy constructor called ! " << endl;
        a = obj.a;
    }
    void display()
    {
        cout << "The number for this object is " << a << endl;
    }
};

int main()
{
    Number x, y, z(45), z2;
    x.display();
    y.display();
    z.display();
    Number z1(z);
    z1.display();
    z2 = z;
    z2.display();
    Number z3 = z;
    z3.display();
    return 0;
}