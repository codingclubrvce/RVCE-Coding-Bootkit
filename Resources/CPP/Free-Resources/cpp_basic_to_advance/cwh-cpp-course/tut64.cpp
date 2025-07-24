#include <iostream>
using namespace std;

template <class T>
class vector
{
    int size;

public:
    T *arr;
    vector(int m)
    {
        size = m;
        arr = new T[size];
    }
    int dotproduct(vector &v)
    {
        T d = 0;
        for (int i = 0; i < size; i++)
        {
            d += this->arr[i] * v.arr[i];
        }
        return d;
    }
};

int main()
{
    cout << "INT" << endl;

    vector<int> v1(3);
    v1.arr[0] = 1;
    v1.arr[1] = 4;
    v1.arr[2] = 1;
    vector<int> v2(3);
    v2.arr[0] = 1;
    v2.arr[1] = 4;
    v2.arr[2] = 9;
    cout << "v1 dot v2 = " << v1.dotproduct(v2) << endl;

    cout << "FLOAT" << endl;

    vector<float> v3(3);
    v3.arr[0] = 1.78;
    v3.arr[1] = 4.55;
    v3.arr[2] = 1;
    vector<float> v4(3);
    v4.arr[0] = 0;
    v4.arr[1] = 4.192;
    v4.arr[2] = 9.30;
    cout << "v1 dot v2 = " << v1.dotproduct(v2) << endl;
    return 0;
}