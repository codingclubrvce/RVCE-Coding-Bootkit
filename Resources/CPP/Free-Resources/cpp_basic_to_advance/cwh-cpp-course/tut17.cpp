#include <iostream>
using namespace std;

inline int product(int a, int b) // function call is replaced by function code
{
    static int c = 0;
    c++;
    return a * b + c;
}

float total(int price, int quantity = 1)  // default arguments should be on the right
{
    return quantity * price;
}
int main()
{
    int a, b;
    cout << "Enter the value of a and b : " << endl;
    cin >> a >> b;

    cout << product(a, b) << endl;
    cout << product(a, b) << endl;
    cout << product(a, b) << endl;
    cout << product(a, b) << endl;
    cout << product(a, b) << endl;
    cout << product(a, b) << endl;
    cout << product(a, b) << endl;
    cout << product(a, b) << endl;
    cout << product(a, b) << endl;

    cout << "The price of 1 apple is = " << total(20) << endl;
    cout << "The price of 5 apples is = " << total(30, 5) << endl;
    return 0;
}