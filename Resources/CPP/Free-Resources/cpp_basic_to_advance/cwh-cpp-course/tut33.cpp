#include <iostream>
using namespace std;

class BankDeposit
{
    int principal;
    int years;
    float rate;
    float returnAmount;

public:
    BankDeposit() {}
    BankDeposit(int p, int y, int r);   // r is in percentage like 13
    BankDeposit(int p, int y, float r); // r is in number like 0.13
    void show();
};

BankDeposit ::BankDeposit(int p, int y, int r)
{
    principal = p;
    years = y;
    rate = r;
    returnAmount = principal;
    for (int i = 0; i < y; i++)
    {
        returnAmount += (returnAmount * r) / 100;
    }
}
BankDeposit ::BankDeposit(int p, int y, float r)
{
    principal = p;
    years = y;
    rate = r;
    returnAmount = principal;
    for (int i = 0; i < y; i++)
    {
        returnAmount = returnAmount * (1 + r);
    }
}
void BankDeposit ::show()
{
    cout << "Principal amount was " << principal << endl;
    cout << "Return value after " << years << " year is " << returnAmount << endl;
}
int main()
{
    BankDeposit bd1, bd2, bd3;
    int p, y;
    float r;
    int R;
    cout << "Enter the value of p y and r" << endl;
    cin >> p >> y >> r;
    bd1 = BankDeposit(p, y, r);
    bd1.show();

    cout << "Enter the value of p y and R" << endl;
    cin >> p >> y >> R;
    bd2 = BankDeposit(p, y, R);
    bd2.show();

    BankDeposit bd3;
    bd3.show();
    return 0;
}