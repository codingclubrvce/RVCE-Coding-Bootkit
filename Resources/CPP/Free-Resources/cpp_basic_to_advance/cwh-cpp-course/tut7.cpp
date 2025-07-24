#include<iostream>
using namespace std;

int c = 36;

int main(){

int a,b;
cin>>a>>b;

int c = a + b;

cout<<c<<endl;
cout<<"global c is "<<::c<<endl;
// socpe resolution operator is :: used to print global value of any variable

float f = 66.2f;
double d = 66.2;

cout<<f<<endl<<d<<endl;

//reference variable

int x = 7;
int & y = x;
cout<<x<<endl<<y<<endl;


//typecasting

char g = 'h';
int num1 = 12;
float num2 = 45.56;

cout<<float(num1)<<endl;
cout<<int(num2)<<endl;
cout<<int(g)<<endl;

return 0;
}