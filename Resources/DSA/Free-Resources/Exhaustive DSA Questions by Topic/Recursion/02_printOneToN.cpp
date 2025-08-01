//Print all number from 1 to N using revursion.

#include<iostream>
using namespace std;

void print(int i, int N){
    if(i>N){
        return;
    }
    cout << i << endl;
    print(i+1, N);
}

int main(){
    int n;
    cin >> n;
    print(1, n);
}