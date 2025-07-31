/*
    Find number appearing only once in an array where all other numbers appear twice
    arr[] = {1, 1, 2, 3, 4, 3, 4}
    ans = 2
*/
#include<vector>
#include<map>
#include<iostream>
using namespace std;

/*
    Brute Force Approach using Linear Search
    TC : O(N^2)
    SC : O(1)
*/
int brute(vector<int> arr, int n){
    for(int i=0; i<n; i++){
        int count = 0;
        int num = arr[i];
        for(int j=0; j<n; j++){
            if(arr[j] == num){
                count++;
            }
        }
        if(count == 1){
            return num;
        }
    }
    return -1;
}

/*
    Better Approach using MAP Data Structure
    TC : O(N log (N/2 + 1)) + O(N/2 + 1)
    SC : O(N/2 + 1)
*/
int better(vector<int> arr, int n){
    map<long long, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}

/*
    Optimal Approach using XOR
    TC : O(N)
    SC : O(1)
*/
int optimal(vector<int> arr, int n){
    int xor1 = 0;
    for(int i=0; i<n; i++){
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}

int main(){
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4};
    int n = arr.size();
    // int ans = brute(arr, n);
    // int ans = better(arr, n);
    int ans = optimal(arr, n);
    cout << ans << endl;
    return 0;
}