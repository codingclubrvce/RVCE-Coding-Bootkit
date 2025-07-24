// #include <iostream>
// #include <cmath>
// using namespace std;

// class ScienticCalculator
// {

// public:
//     int a;
//     int b;
//     int n;

//     void setop()
//     {
//         cout << "Enter the operation number that you want to perform" << endl;
//         cin >> n;
//     }
//     float operations(int a, int b, int n)
//     {

//         switch (n)
//         {
//         case 5:
//             return pow(a, b);
//             break;
//         case 6:
//             return hypot(a, b);
//             break;
//         case 7:
//             return max(a, b);
//             break;
//         case 8:
//             return min(a, b);
//             break;
//         }
//     }
// };
// class SimpleCalculator
// {

// public:
//     int a;
//     int b;
//     int n;
//     int setop()
//     {
//         cout << "Enter the operation number that you want to perform" << endl;
//         cin >> n;
//         return n;
//     }
//     float operations(int a, int b, int n)
//     {
//         switch (n)
//         {
//         case 1:
//             return a + b;
//             break;
//         case 2:
//             return a - b;
//             break;
//         case 3:
//             return a * b;
//             break;
//         case 4:
//             return a / b;
//             break;
//         }
//     }
// };
// class HybridCalculator : public ScienticCalculator, public SimpleCalculator
// {
// public:
//     int a, b, n;
//     void setdata(int x, int y)
//     {
//         a = x;
//         b = y;
//     }
//     void instructions()
//     {
//         cout << "INSTRUCTIONS :" << endl;
//         cout << "1 add" << endl;
//         cout << "2 subtract" << endl;
//         cout << "3 multiply" << endl;
//         cout << "4 divide" << endl;
//         cout << "5 pow" << endl;
//         cout << "6 hypotenuse" << endl;
//         cout << "7 max" << endl;
//         cout << "8 min" << endl;
//     }
//     int setop()
//     {
//         cout << "Enter the operation number that you want to perform" << endl;
//         cin >> n;
//         return n;
//     }
// };

// int main()
// {
//     int a;
//     int b;
//     cout << "Enter 2 numbers : " << endl;
//     cin >> a >> b;
//     HybridCalculator h;
//     h.instructions();
//     int x = h.setop();
//     h.setdata(a, b, x);
//     return 0;
// }
#include <iostream>
#include <cmath>
using namespace std;
class simple
{
protected:
    int a, b;

public:
    void set1Data(int num, int num1)
    {
        a = num;
        b = num1;
    }
    void display(void)
    {
        cout << "Addition is: " << a + b << endl;
        cout << "Substraction is: " << a - b << endl;
        cout << "Multiplication is: " << a * b << endl;
        cout << "Division is: " << a / b << endl;
    }
};
class scientific
{
protected:
    int x, y;

public:
    void set2Data(int num, int num1)
    {
        x = num;
        y = num1;
    }
    void process(void)
    {
        cout << "The square root of x is " << sqrt(x) << endl;
        cout << "The square root of y is " << sqrt(y) << endl;
        cout << "The cube root of x is  " << cbrt(x) << endl;
        cout << "The cube root of y is " << cbrt(y) << endl;
    }
};

class hybrid : public simple, public scientific
{
public:
    void set(int a, int b)
    {
        simple::set1Data(a, b);
        simple::display();
        scientific::set2Data(a, b);
        scientific::process();
    }
};

int main()
{
    int p, q;
    cout << "Enter two number: " << endl;
    cin >> p >> q;

    hybrid h;
    h.set(p, q);
    return 0;
}