#include<iostream>
using namespace std;

int main(){
    //pointers --> it is a data type that holds the adress of another data type

    int a = 9;
    int * b = &a;

    cout<<&a<<endl;
    cout<<b<<endl;

    //& --> address of operator
    //* --> dereference of operator
cout<<"the value at address b is "<<*b<<endl;

int **c = &b;
cout<<&b<<endl;
cout<<**c<<endl;

    return 0;
}