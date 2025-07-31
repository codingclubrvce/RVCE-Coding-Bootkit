// Sort an Array containing 0's , 1's and 2's

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

/*
    Brute Force - Use Merge Sort
    TC : O(NlogN)
    SC : O(N)
*/

/*
    Better - Use Counters
    TC : O(2N)
    SC : O(N)
*/
void better(vector<int> arr){
    int n = arr.size();
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            c0++;
        }
        if(arr[i] == 1){
            c1++;
        }
        if(arr[i] == 2){
            c2++;
        }
    }
    vector<int> result;
    for(int i=0; i<c0; i++){
        result.push_back(0);
    }
    for(int i=c0; i<c0+c1; i++){
        result.push_back(1);
    }
    for(int i=c0+c1; i<c0+c1+c2; i++){
        result.push_back(2);
    }
    for(auto it : result){
        cout << it << " ";
    }
}

/*
    Optimal - Dutch National Flag Algorithm - 3 pointer approach
    0 to low-1 = 0
    low to mid-1 = 1
    mid to high = unsorted
    high+1 to n = 2
    TC : O(N)
    SC : O(1)
*/
void optimal(vector<int> arr){
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for(auto it : arr){
        cout << it << " ";
    }
}

int main(){
    vector<int> arr = {0, 0, 1, 1, 2, 0, 1, 0, 2, 1, 1, 2, 0};
    // better(arr);
    optimal(arr);
}