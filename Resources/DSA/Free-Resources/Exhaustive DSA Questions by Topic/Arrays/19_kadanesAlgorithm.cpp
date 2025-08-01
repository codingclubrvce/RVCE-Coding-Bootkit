/*
    Maximum Subarray Sum
    arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
    ans = 7
*/

#include<iostream>
#include<vector>
using namespace std;

/*
    Brute Force - Nested For Loops
    TC : O(N)
    SC : O(1)
*/
int brute(vector<int> arr){
    int maxSum = 0;
    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j=i; j<arr.size(); j++){
            sum = sum + arr[j];
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

/*
    Optimal - Kadane's Algorithm
    TC : O(N)
    SC : O(1)
*/
int optimal(vector<int> arr){
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum = sum + arr[i];
        if(sum>maxSum){
            maxSum = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum;
}

int main(){
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    // int ans = brute(arr);
    int ans = optimal(arr);
    cout << ans << endl;
}