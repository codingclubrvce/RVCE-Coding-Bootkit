#include <iostream>
using namespace std;

template <class T1, class T2>
float average(T1 a, T2 b)
{
    float avg = (a + b) / 2;
    return avg;
}

template <class T>
void swapp(T a, T b)
{
    cout << "Beforer swapping : " << a << " " << b << endl;
    T temp;
    temp = a;
    a = b;
    b = temp;
    cout << "After swapping : " << a << " " << b << endl;
}
int main()
{
    cout << average(7.599, 12.456) << endl;
    cout << average(5, 10) << endl;

    swapp(6, 2);
    return 0;
}