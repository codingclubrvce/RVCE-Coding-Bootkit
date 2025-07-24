#include <iostream>
using namespace std;
int count = 0;
class student
{
    int rollno;
    int age;

public:
    student()
    {
        count++;
        cout << "Constructor called !!" << count << endl;
    }
    ~student()
    {
        cout << "Destructor called !!" << count << endl;
        count--;
    }
};
int main()
{
    student s1;
    {
        cout << "Entering separate block :" << endl;
        student p, q;
    }
    student s2;
    return 0;
}