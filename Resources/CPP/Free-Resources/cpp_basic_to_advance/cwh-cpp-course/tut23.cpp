#include <iostream>
using namespace std;

class shop
{
    int itemId[100];
    int itemPrice[100];
    int counter;
    int total = 0;

public:
    void initiatectr(void) { counter = 0; }
    void setPrice(void);
    void displayPrice(void);
};

void shop ::setPrice(void)
{
    cout << "Enter id of your item number " << (counter + 1) << endl;
    cin >> itemId[counter];
    cout << "Enter price of your item " << endl;
    cin >> itemPrice[counter];
    counter++;
}

void shop ::displayPrice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of the item with id " << itemId[i] << " is " << itemPrice[i] << endl;
    }

    for (int i = 0; i < counter; i++)
    {
        total = total + itemPrice[i];
    }
    cout << "Total amount = " << total << endl;
}
int main()
{
    int n;
    cout << "Enter the number of items : " << endl;
    cin >> n;
    shop medical;
    medical.initiatectr();
    for (int i = 0; i < n; i++)
    {
        medical.setPrice();
    }
    medical.displayPrice();
    return 0;
}