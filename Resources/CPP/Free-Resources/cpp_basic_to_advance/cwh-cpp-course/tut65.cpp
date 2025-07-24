#include <iostream>
using namespace std;

// CLASS TEMPLATES WITH MULTIPLE PARAMETERS
// template <class T1 ,class T2 ,class T3 ,....>

template <class T1, class T2>
class myclass
{
    T1 data1;
    T2 data2;

public:
    myclass(T1 a, T2 b)
    {
        data1 = a;
        data2 = b;
    }
    void display()
    {
        cout << "Data 1 = " << this->data1 << endl;
        cout << "Data 2 = " << this->data2 << endl;
    }
};

int main()
{
    myclass<int, char> obj1(5, '&');
    obj1.display();

    myclass<float, int> obj2(5.982, '#');
    obj2.display();
    return 0;
}