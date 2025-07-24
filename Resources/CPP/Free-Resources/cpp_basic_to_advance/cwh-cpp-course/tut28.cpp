#include <iostream>
using namespace std;

class Y;
class X
{
    int data;

public:
    void setvalue(int a)
    {
        data = a;
    }
    friend void add(X o1, Y o2);
};

class Y
{
    int num;

public:
    void setvalue(int a)
    {
        num = a;
    }
    friend void add(X o1, Y o2);
};

void add(X o1, Y o2)
{
    cout << "Summing datas of X and Y objects " << (o1.data + o2.num) << endl;
}
int main()
{
    X a1;
    a1.setvalue(90);
    Y b1;
    b1.setvalue(24);
    add(a1, b1);
    return 0;
}