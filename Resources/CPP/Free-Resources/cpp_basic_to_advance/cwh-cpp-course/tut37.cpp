#include <iostream>
using namespace std;

class Company
{
public:
    int id;
    float salary;
    Company() {}
    Company(int i)
    {
        id = i;
        salary = 34.0;
    }
};
// default visibility mode is private
class Employee : public Company
{
    int code;
// private members are never inherited
public:
    Employee(int i)
    {
        id = i;
        salary = 0;
        code = 0;
    }
    void printcode()
    {
        cout << "Enter code number of the employee" << endl;
        cin >> code;
        cout << "Code number is " << code << endl;
    }
};

int main()
{
    Company tcs(2), hcl(6);
    cout << tcs.id << endl;
    Employee vishal(6);
    cout << vishal.id << endl;
    vishal.printcode();
    cout << hcl.id << endl;

    return 0;
}