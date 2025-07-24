#include <iostream>
using namespace std;

template <class T>
class vector
{
    T *arr;

public:
    vector(T *arr)
    {
        // code
    }
    // other methods
};

int main()
{
    int *ptr1;
    vector<int> v(ptr1);
    float *ptr2;
    vector<float> f(ptr2);
    return 0;
}