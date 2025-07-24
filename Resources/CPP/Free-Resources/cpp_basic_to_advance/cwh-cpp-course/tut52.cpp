#include <iostream>
using namespace std;

class Shop
{
    int id;

public:
    float price;
    int qty;
    void setdata(int x, float y, int z)
    {
        id = x;
        price = y;
        qty = z;
    }
    void getdata()
    {
        cout << "Item id = " << id << endl;
        cout << "Item price = " << price << endl;
        cout << "Item quantity = " << qty << endl;
    }
};

int main()
{
    int size = 2;
    int total = 0;
    Shop *ptr = new Shop[size];
    Shop *ptrtemp = ptr;

    for (int i = 0; i < size; i++)
    {
        int a, c;
        float b;
        cout << "Enter id of item number " << i + 1 << " : " << endl;
        cin >> a;
        cout << "Enter price of item " << i + 1 << " : " << endl;
        cin >> b;
        cout << "Enter quantity of item " << i + 1 << " : " << endl;
        cin >> c;
        ptr->setdata(a, b, c);
        total += c * (*ptr).price;
        ptr++;
    }
    cout << endl;
    cout << "\tShopping list\n"
         << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Item number " << i + 1 << " : " << endl;
        ptrtemp->getdata();
        ptrtemp++;
    }

    cout << "\n\n Total amount = " << total << endl;

    return 0;
}