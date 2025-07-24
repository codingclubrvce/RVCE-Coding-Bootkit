#include <iostream>
using namespace std;

class Base
{
public:
    int var_base = 100;
    virtual void display()
    {
        cout << "1 Displaying base class variable " << var_base << endl;
    }
};
class Derived : public Base
{
public:
    int var_derived = 200;
    void display()
    {
        cout << "2 Displaying base class variable " << var_base << endl;
        cout << "2 Displaying derived class variable " << var_derived << endl;
    }
};

int main()
{
    Base *base_class_ptr;
    Base obj_base;
    Derived obj_derived;
    base_class_ptr = &obj_derived; // base class pointer is pointing to an object of the derived class
    base_class_ptr->display();     // base class function is called always when base pointer to derived class is used
    // to change this default behaviour virtual functions are used
    // if the display() function in base class is made virtual no always display() from derived class will be called even if the base class pointer is used
    return 0;
}