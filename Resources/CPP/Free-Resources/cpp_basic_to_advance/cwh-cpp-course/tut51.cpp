#include <iostream>
using namespace std;

class Complex
{
    int real;
    int img;

public:
    void setdata(int x, int y)
    {
        real = x;
        img = y;
    }
    void getdata()
    {
        cout << "The real part of c is " << real << endl;
        cout << "The imaginary part of c is " << img << endl;
    }
};

int main()
{
    Complex c1;
    c1.setdata(2, 5);
    c1.getdata();

    //  Complex *ptr = &c1; is same as :
    Complex *ptr = new Complex;
    cout << "Using pointer :" << endl;
    //  (*ptr).setdata(5, 1); is same as :
    ptr->setdata(5, 1);
    ptr->getdata();

    // Creating an array of objects :
    cout << "Creating an array of objects" << endl;
    Complex *ptr1 = new Complex[3];
    for (int i = 1; i <= 3; i++)
    {
        cout << "Object " << i << " : " << endl;
        int a, b;
        cout << "Enter real part :" << endl;
        cin >> a;
        cout << "Enter imaginary part :" << endl;
        cin >> b;
        ptr1->setdata(a, b);
        ptr1->getdata();
    }

    return 0;
}