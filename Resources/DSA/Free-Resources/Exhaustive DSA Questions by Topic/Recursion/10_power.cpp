#include<bits/stdc++.h>
using namespace std;


int power(int x, int p, int i){
    if(i == p){
        return 1;
    }
    else{
        return x*power(x, p, ++i);
    }
}

int main(){
    int x = 3;
    int p = 4;
    int ans = power(x, p, 0);
    cout << ans << endl;
}