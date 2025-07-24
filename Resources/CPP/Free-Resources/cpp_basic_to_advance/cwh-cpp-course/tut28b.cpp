#include <iostream>
using namespace std;

class C2;
class C1
{
    int val;
    friend void exchange(C1 &x, C2 &y);

public:
    void setvalue(int a)
    {
        val = a;
    }
    void display(void)
    {
        cout << val << endl;
    }
};

class C2
{
    int ans;
    friend void exchange(C1 &x, C2 &y);

public:
    void setvalue(int a)
    {
        ans = a;
    }
    void display(void)
    {
        cout << ans << endl;
    }
};
void exchange(C1 &x, C2 &y)
{
    int temp = x.val;
    x.val = y.ans;
    y.ans = temp;
}

int main()
{
    C1 oc1;
    C2 oc2;

    oc1.setvalue(34);
    oc2.setvalue(57);
    oc1.display();
    oc2.display();

    exchange(oc1, oc2);
    oc1.display();
    oc2.display();
    return 0;
}