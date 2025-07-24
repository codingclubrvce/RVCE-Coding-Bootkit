#include <iostream>
using namespace std;

struct employee
{
    int Id;
    char favChar;
    float salary;
};

union money
{
    int rice;
    char car;
    float pounds;
};

int main()
{

    struct employee harry;
    harry.Id = 1;
    harry.favChar = 'c';
    harry.salary = 1200000;

    cout << harry.Id << endl;
    cout << harry.favChar << endl;
    cout << harry.salary << endl;

    union money vishal;
    vishal.rice = 34;
    cout << vishal.rice << endl;
    cout << sizeof(vishal.rice) << endl;

    enum Meal
    {
        breakfast,
        lunch,
        dinner
    };
    Meal vl = breakfast;
    cout << breakfast << endl;

    cout << sizeof(harry) << endl;
    cout << sizeof(vishal) << endl;

    return 0;
}