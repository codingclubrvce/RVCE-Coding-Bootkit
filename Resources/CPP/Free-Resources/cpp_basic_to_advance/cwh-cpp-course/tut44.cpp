#include <iostream>
using namespace std;

class student
{
public:
    int marks1;
    int attendance1;
    void set_data(int m, int a)
    {
        marks1 = m;
        attendance1 = a;
    }
};
class marks : virtual public student
{
public:
    void show()
    {
        cout << "Marks = " << marks1 << endl;
    }
};
class attendance : virtual public student
{
public:
    void show()
    {
        cout << "Attendance = " << attendance1 << endl;
    }
};

class record : public marks, public attendance
{
public:
    void display_data()
    {
        marks ::show();
        attendance::show();
        if (marks1 > 33 && attendance1 > 75)
        {
            cout << "Pass" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }
};

int main()
{
    record vishal;
    vishal.set_data(98, 56);
    vishal.display_data();

    return 0;
}