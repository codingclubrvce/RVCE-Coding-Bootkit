#include <iostream>
using namespace std;

class employee
{
    int id;
    int salary;
    static int count;

public:
    void setId(void)
    {
        count++;
        cout << "Employee number : " << count << endl;
        cout << "Enter the id of the employee" << endl;
        cin >> id;
    }
    void getId(void)
    {
        cout << "The id of this employee is " << id << endl;
    }
};

int employee ::count;

int main()
{
    employee harry;
    harry.setId();
    harry.getId();

    // creating an array of objects
    employee meta[4];
    for (int i = 0; i < 4; i++)
    {
        meta[i].setId();
        meta[i].getId();
    }

    return 0;
}