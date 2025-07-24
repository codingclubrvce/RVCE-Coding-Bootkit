#include <iostream>
using namespace std;

template <class T>
class myclass
{
public:
    T data;
    myclass(T a)
    {
        data = a;
    }
    void display();
};

template <class T>
void myclass<T>::display()
{
    cout << "The value of a is " << data << endl;
}

// template function overloading
void func(int a)
{
    cout << "I am first func() : " << a << endl;
}

template <class T>
void func(T a)
{
    cout << "I am templatised func() : " << a << endl;
}

int main()
{
    myclass<int> obj1(7);
    cout << obj1.data << endl;
    obj1.display();

    myclass<float> obj2(7.482);
    cout << obj2.data << endl;
    obj2.display();

    cout << "Using func() :" << endl;
    func(5); // first func is executed instead of template (exact match has higher priority)
    func(4.820);
    func('^');
    return 0;
}