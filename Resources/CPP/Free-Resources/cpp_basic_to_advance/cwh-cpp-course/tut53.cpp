#include <iostream>
using namespace std;

class A
{
    int a;

public:
    void setdata(int a)
    {
        this->a = a; // this is a pointer to the object that invokes the member function
    }
    void getdata()
    {
        cout << "The value of a is " << a << endl;
    }
};

int main()
{
    A obj;
    obj.setdata(7);
    obj.getdata();
    return 0;
}