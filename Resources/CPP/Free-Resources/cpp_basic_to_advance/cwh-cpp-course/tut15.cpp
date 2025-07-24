#include<iostream>
using namespace std;

int sum(int a , int b){
    cout<<"Enter first number"<<endl;
cin>>a;
    cout<<"Enter second number"<<endl;
cin>>b;

cout<<"the sum of two numbers is "<<(a+b)<<endl;
}

int main(){
    int a,b;
    sum(a,b);
    return 0;
}