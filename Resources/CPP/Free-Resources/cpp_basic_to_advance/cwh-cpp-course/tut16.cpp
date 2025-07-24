#include <iostream>
using namespace std;

int sum(int a, int b)
{
    int c = a + b;
    return c;
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapptr(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 4;
    int b = 5;

    swap(a, b);

    cout << "the sum of 4 and 5 is " << sum(a, b) << endl;
    swapptr(&a, &b);
    cout << "The value a is " << a << " and the value of b is " << b << endl;
    return 0;
}