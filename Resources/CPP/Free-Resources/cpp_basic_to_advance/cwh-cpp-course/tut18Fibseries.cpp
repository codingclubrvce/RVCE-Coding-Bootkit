#include<iostream>
using namespace std;

int fibSeries(int n){
    if(n<=2){
        return 1;
    }else{
        return fibSeries(n-1)+fibSeries(n-2);
    }
}

int main(){
    
    int n;
    cin>>n;

    cout<<"the required term of the fibonacci series is "<<fibSeries(n)<<endl;
    return 0;
}