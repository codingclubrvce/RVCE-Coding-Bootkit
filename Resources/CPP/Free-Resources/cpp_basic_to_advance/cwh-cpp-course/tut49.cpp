#include <iostream>
using namespace std;

class student1
{
    int a, b;

public:
    student1(int x, int y) : a(x), b(y)
    {
        cout << "Student1 constuctor called" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

class student2
{
    int a, b;

public:
    student2(int x, int y) : a(x)
    {
        b = y;
        cout << "Student2 constuctor called" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

class student3
{
    int a, b;

public:
    student3(int x, int y) : a(x), b(y + x)
    {
        cout << "Student3 constuctor called" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

class student4
{
    int a, b;

public:
    student4(int x, int y) : a(x), b(y * x)
    {
        cout << "Student4 constuctor called" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

class student5
{
    int a, b;

public:
    student5(int x, int y) : a(x), b(y * 4)
    {
        cout << "Student5 constuctor called" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

class student6
{
    int a;
    int b;

public:
    student6(int x, int y) : b(y * 4), a(b + x) // always check order in which the variables are initialized
    {
        cout << "Student6 constuctor called" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

class student7
{
    int b;
    int a;

public:
    student7(int x, int y) : b(y * 4), a(b + x)
    {
        cout << "Student7 constuctor called" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};
int main()
{
    student1 s1(2, 3);
    student2 s2(2, 3);
    student3 s3(2, 3);
    student4 s4(2, 3);
    student5 s5(2, 3);
    student6 s6(2, 3);
    student7 s7(2, 3);

    return 0;
}