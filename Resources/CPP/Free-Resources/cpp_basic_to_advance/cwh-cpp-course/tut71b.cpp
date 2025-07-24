#include <iostream>
#include <vector>
using namespace std;

template <class T>
void display(vector<T> &v)
{
    cout << "Elements of the vector are : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;      // 0 length vector
    vector<char> v1(4); // 4 element char vector
    v1.push_back('!');
    v1.push_back('#');
    v1.push_back('$');
    v1.push_back('%');
    vector<char> v2(v1);  // 4 element char vector
    vector<int> v3(6, 3); // 6 element vector 3s

    int ele, size;
    cout << "Enter the size of vector " << endl;
    cin >> size;
    cout << "Enter vector elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> ele;
        v.push_back(ele);
    }
    display(v);

    // cout << "After popping 1 time : " << endl;
    // v.pop_back();
    // display(v);
    // cout << "After popping 2 times : " << endl;
    // v.pop_back();
    // display(v);

    // creating an iterator
    // vector<int>::iterator iter = v.begin();
    // v.insert(iter, 82);
    // cout << "After inserting 82 at 1 pos : " << endl;
    // display(v);

    // v.insert(iter + 1, 11);
    // cout << "After inserting 11 at 2 pos : " << endl;
    // display(v);

    // v.insert(iter + 2, 4, 50);
    // cout << "After inserting 4 copies of 50 at 3 pos : " << endl;
    // display(v);

    cout << "Displaying v1 : " << endl;
    display(v1);
    cout << "Displaying v2 : " << endl;
    display(v2);
    cout << "Displaying v3 : " << endl;
    display(v3);
    return 0;
}