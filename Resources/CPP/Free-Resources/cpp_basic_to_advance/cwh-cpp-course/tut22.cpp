#include <iostream>
using namespace std;

class binary
{
    string s;

public:
    void read(void);
    void chk_bin(void);
    void ones(void);
};

void binary ::read(void)
{
    cout << "Enter a binary number" << endl;
    cin >> s;
}

void binary ::chk_bin(void)
{
    bool flag = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '1' && s.at(i) != '0')
        {
            flag = 0;
        }
    }

    if (flag)
    {
        cout << "Correct binary format" << endl;
    }
    else
    {
        cout << "Incorrect binary format" << endl;
    }
}

void binary ::ones(void)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '1')
        {
            s.at(i) = '0';
        }
        else
        {
            s.at(i) = '1';
        }
    }
    cout << "The new number is " << s << endl;
}

int main()
{
    binary b;
    b.read();
    b.chk_bin();
    b.ones();
    return 0;
}