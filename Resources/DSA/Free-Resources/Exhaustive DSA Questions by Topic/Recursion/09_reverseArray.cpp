#include<bits/stdc++.h>
using namespace std;

vector<int> a = {1, 2, 3, 4};
int n = 4;

void rev(vector<int>& a, int i){
    if(i >= n/2){
        return;
    }
    else{
        int temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
        return rev(a, ++i);
    }
}

int main(){
    for(int i = 0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    rev(a, 0);
    for(int i = 0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}