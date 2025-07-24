#include<iostream>
#include<iomanip>
using namespace std;

int main(){

//if else
cout<<"Tell me your age "<<endl;

int age;
cin>>age;

if(age>=18){
    cout<<"You are an adult "<<endl;
    }else{
        cout<<"You are not an adult "<<endl;
    }


//switch case
switch(age){

    case 18 :
    cout<<"You are 18"<<endl;
    break;

    case 2 :
    cout<<"You are 2"<<endl;
    break;

    default :
    cout<<"No special cases";
}
return 0;
}