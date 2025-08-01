//Print sum of all numbers from 1 to N using revursion.

#include<iostream>
using namespace std;

int findSum(int n){
    if(n==0){
        return 0;
    }
    else 
        return n + findSum(n-1);
}

int main(){
    int n;
    cin >> n;
    int sum = findSum(n);
    cout << "Sum of first " << n << " numbers is: " << sum << endl;
}