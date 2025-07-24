#include <iostream>
#include <cmath>
using namespace std;

class simplecalc
{
    int a;
    int b;

public:
    void get_datasimple()
    {
        cout << "Enter the value of a " << endl;
        cin >> a;
        cout << "Enter the value of b " << endl;
        cin >> b;
    }

    void display_datasimple()
    {
        cout << "The value of a + b is " << a + b << endl;
        cout << "The value of a - b is " << a - b << endl;
        cout << "The value of a * b is " << a * b << endl;
        cout << "The value of a % b is " << a % b << endl;
    }
};

class scientificcalc
{
    int a;
    int b;

public:
    void get_datascientific()
    {
        cout << "Enter the value of a " << endl;
        cin >> a;
        cout << "Enter the value of b " << endl;
        cin >> b;
    }

    void display_datascientific()
    {
        cout << "The value of sin(a) is " << sin(a) << endl;
        cout << "The value of cos(a) is " << cos(a) << endl;
        cout << "The value of exp(a) is " << exp(a) << endl;
        cout << "The value of a^b is " << pow(a, b) << endl;
    }
};

class hybridcalc : public simplecalc, public scientificcalc
{
};
int main()
{
    // simplecalc c1;
    // c1.get_datasimple();
    // c1.display_datasimple();
    // cout << endl
    //      << endl;
    // scientificcalc c2;
    // c2.get_datascientific();
    // c2.display_datascientific();
    // cout << endl
    //      << endl;

    hybridcalc h;
    h.get_datascientific();
    h.display_datascientific();
    h.get_datasimple();
    h.display_datasimple();
    return 0;
}