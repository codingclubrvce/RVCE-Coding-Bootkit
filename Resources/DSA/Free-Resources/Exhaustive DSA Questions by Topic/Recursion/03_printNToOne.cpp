//Print all number from N to 1 using revursion.

#include<iostream>
using namespace std;

void print(int i, int N){
    if(i>N){
        return;
    }
    cout << N << endl;
    print(1, N-1);
}

int main(){
    int n;
    cin >> n;
    print(1, n);
}