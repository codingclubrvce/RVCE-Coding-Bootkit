#include <iostream>
using namespace std;

// TEMPLATES WITH DEFAULT ARGUMENTS

template <class T1 = int, class T2 = float, class T3 = char>
class myClass
{
    T1 a;
    T2 b;
    T3 c;

public:
    myClass(T1 x, T2 y, T3 z)
    {
        a = x;
        b = y;
        c = z;
    }
    void display()
    {
        cout << "The value of a is " << this->a << endl;
        cout << "The value of b is " << this->b << endl;
        cout << "The value of c is " << this->c << endl;
    }
};
int main()
{
    cout << "object 1 : " << endl;
    myClass<> obj1(36, 2.715, '@');
    obj1.display();

    cout << "object 2 : " << endl;
    myClass<char, char, double> obj2('*', '@', 5.98340);
    obj2.display();
    return 0;
}