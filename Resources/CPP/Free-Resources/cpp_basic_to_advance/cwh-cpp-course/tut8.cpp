#include<iostream>
#include<iomanip>
using namespace std;

int main(){

int a = 9;
a = 10;

cout<<a<<endl;

//constants in c++
const int b = 6;
cout << b <<endl;

//manipulators setw
int x = 78;
int y = 2;
int z = 456;

cout<<"value of x without setw is "<<x<<endl;
cout<<"value of y without setw is "<<y<<endl;
cout<<"value of z without setw is "<<z<<endl;

cout<<"value of x with setw is "<<setw(4)<<x<<endl;
cout<<"value of y with setw is "<<setw(4)<<y<<endl;
cout<<"value of z with setw is "<<setw(4)<<z<<endl;

//operators precendce
int p = 9,q = 10, r = 7;
//if precedence is same then check associativity 
int hello = p+q*r-p*q;
int mello = p+q*r;
cout<<hello<<endl;
cout<<mello<<endl;

    return 0;
}