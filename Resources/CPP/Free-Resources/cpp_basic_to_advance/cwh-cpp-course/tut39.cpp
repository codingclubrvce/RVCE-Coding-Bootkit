#include <iostream>
using namespace std;

class Base
{
protected:
    int a;

private:
    int b;

public:
    int c;
    int getb()
    {
        return b;
    }
    Base()
    {
        a = 30;
        b = 10;
        c = 90;
    }
};

class Derived : protected Base
{
public:
    void add()
    {
        cout << (a + getb() + c);
    }
};
int main()
{
    Derived der;
    der.add();
    return 0;
}