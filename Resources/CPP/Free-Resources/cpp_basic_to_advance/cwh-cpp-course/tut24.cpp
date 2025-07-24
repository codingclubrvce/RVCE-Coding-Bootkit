#include <iostream>
using namespace std;

class employee
{
    int id;
    // static data member
    static int count; // 0 by default
public:
    void setData(void)
    {
        cout << "Enter the id" << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "Your id is " << id << endl;
    }
    // static member functon
    static void getCount(void)
    {
        cout << "The value of count is " << count << endl;
    }
};

int employee ::count = 0;
int main()
{
    employee vishal;
    vishal.setData();
    vishal.getData();
    employee ::getCount();

    employee mayur;
    mayur.setData();
    mayur.getData();
    employee ::getCount();

    return 0;
}