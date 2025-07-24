#include <iostream>
#include <list>
using namespace std;

void display(list<int> &ls)
{
    list<int>::iterator it = ls.begin();
    for (; it != ls.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> list1; // list of 0 length
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    list<int> list2; // empty list of 5 length
    list2.push_back(13);
    list2.push_back(29);
    list2.push_back(7);
    list2.push_back(42);
    list2.push_back(15);
    list2.push_back(6);
    list2.push_back(97);
    cout << "List elements are :" << endl;
    display(list2);

    // list<int> list3; --> empty list of 0 length
    // int n;
    // cout << "Enter the number of elements :" << endl;
    // cin >> n;
    // int ele;
    // list<int>::iterator itr = list3.begin();
    // for (; itr != list3.end(); itr++)
    // {
    //     cin >> ele;
    // }

    list2.pop_back();
    cout << "After popping back 1 time " << endl;
    display(list2);

    list2.pop_front();
    cout << "After popping front 1 time " << endl;
    display(list2);

    list2.remove(3);
    cout << "After removing 3 from the list " << endl;
    display(list2);

    list2.sort();
    cout << "After sorting the list " << endl;
    display(list2);

    // merging list1 and list2
    list1.merge(list2);
    cout << "Displaying the elements of the merge list1 " << endl;
    display(list1);

    list1.reverse();
    cout << "After reversing the list1 " << endl;
    display(list1);

    return 0;
}