#include <iostream>
using namespace std;

class Base
{
public:
    int var_base;
    void display()
    {
        cout << "Displaying base class variable " << var_base << endl;
    }
};
class Derived : public Base
{
public:
    int var_derived;
    void display()
    {
        cout << "Displaying base class variable " << var_base << endl;
        cout << "Displaying derived class variable " << var_derived << endl;
    }
};

int main()
{
    Base *base_class_ptr;
    Base obj_base;
    Derived obj_derived;
    base_class_ptr = &obj_derived; // base class pointer is pointing to an object of the derived class
    base_class_ptr->var_base = 32;
    base_class_ptr->display();
    // base_class_ptr->var_derived = 359;  only base class inherited properties can be accessed by the pointer
    base_class_ptr->var_base = 3200;
    base_class_ptr->display();

    // Creating a pointer to derived class
    cout << "New" << endl;
    Derived *derived_class_ptr;
    derived_class_ptr = &obj_derived;
    derived_class_ptr->var_derived = 25;
    derived_class_ptr->display();
    return 0;
}