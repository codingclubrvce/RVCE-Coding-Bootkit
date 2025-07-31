#include <bits/stdc++.h>
using namespace std;

void toh(int n, char from, char to, char temp){
    if(n==0) return;
    toh(n-1, from, temp, to);
    cout << "moved disk " << n << " from " << from << " to " << to << endl;
    toh(n-1, temp, to, from);
}

int main(){
    int n = 3;
    toh(n, 'A', 'C', 'B');
    return 0;
}