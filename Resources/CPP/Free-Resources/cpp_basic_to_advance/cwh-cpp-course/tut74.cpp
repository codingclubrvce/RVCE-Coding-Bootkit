#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
    // function objects (functors) --> function wrapped in a class so that it is available like an object

    int arr[] = {1, 4, 32, 65, 3, 98, 11};
    cout << "Before sorting : " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, arr + 7);
    cout << "After sorting : " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // passing a functor as argument
    sort(arr, arr + 7, greater<int>());
    cout << "After passing functor in sorting : " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}