#include <iostream>
using namespace std;

class base1
{
public:
    void greet()
    {
        cout << "How are you ?" << endl;
    }
};
class base2
{
public:
    void greet()
    {
        cout << "Kiase ho ?" << endl;
    }
};
class derived : public base1, public base2
{
public:
    int a;
    void greet()
    {
        base1 ::greet(); // ambiguity removed
    }
};

int main()
{
    base1 ob1;
    ob1.greet();
    base2 ob2;
    ob2.greet();
    derived d;
    d.greet();
    // d.greet(); Ambiguity in multiple inheritance

    return 0;
}