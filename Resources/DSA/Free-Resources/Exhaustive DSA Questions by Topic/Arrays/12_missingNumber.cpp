/*
    Given arr[] = [1, 2, 4, 5]
    n = 5
    answer = 3
*/

#include<vector>
#include<iostream>
using namespace std;
/*
    Optimal - XOR Approach
    TC : O(N)
    SC : O(N)
*/
int optimalXOR(vector<int> arr, int n){
    int xor1 =0;
    int xor2 = 0;
    for(int i=0; i<n-1; i++){
        xor1 = xor1 ^ (i+1);
        xor2 = xor2 ^ arr[i];
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}
/*
    Optimal - Sum Approach
    TC : O(N)
    SC : O(1)
*/
int optimalSUM(vector<int> arr, int n){
    int sum = 0;
    int s2 = 0;
    sum = n*(n+1)/2;
    // cout << sum << endl;
    for(int i=0; i<n-1; i++){
        s2 = s2 + arr[i];
    }
    // cout << s2 << endl;
    return sum-s2;
}
/*
    Better - Hashing Approach
    TC : O(N) + O(N)
    SC : O(N)
*/
int hashing(vector<int> &arr, int n){
    vector<int> hash(n+1, 0);
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    for(int i=1; i<=n; i++){
        if(hash[i]==0){
            return i;
        }
    }
    return n;
}
/*
    Brute - Linear Search Approach
    TC : O(N^2)
    SC : O(1)
*/
int linearSearch(vector<int> &arr, int n){
    for(int i=1; i<n; i++){
        int flag = 0;
        for(int j=0; j<n; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            return i;
        }
    }
    return n;
}

int main(){

    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    // int ans = optimalSUM(arr, n);
    // int ans = hashing(arr, n);
    // int ans = linearSearch(arr, n);
    int ans = optimalXOR(arr, n);
    cout << ans << endl;
    return 0;
}   
