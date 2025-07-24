#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int *ptr = &a;
    cout << "The value of a is " << a << endl;
    cout << "The address of a is " << ptr << endl;
    cout << "The value at address of a is " << *ptr << endl;

    int *p = new int(60);
    cout << "The address of p is " << p << endl;
    cout << "The value at address of p is " << *p << endl;

    float *q = new float(23.99);
    cout << "The address of q is " << q << endl;
    cout << "The value at address of q is " << *q << endl;

    int *array = new int[3];
    array[0] = 6;
    array[1] = 7;
    array[2] = 8;
    array[3] = 9;
    for (int i = 1; i <= 4; i++)
    {
        cout << (*array)++ << endl;
    }

    // delete operator
    delete[] array;
    cout << "After using delete operator :" << endl;
    for (int i = 1; i <= 4; i++)
    {
        cout << (*array)++ << endl;
    }
    return 0;
}