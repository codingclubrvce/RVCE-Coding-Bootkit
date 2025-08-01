#include<map>
#include<vector>
#include<iostream>
using namespace std;

/*
    Brute Force Solution
    TC : O(N^2)
    SC : O(1)
*/
int brute(vector<int> &arr, long long k){
    int len = 0;
    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j=i; j<arr.size(); j++){
            sum = sum + arr[j];
            if(sum == k){
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}

/*
    Better Approach using HASHMAP
    This is approach is better for positive array and it is optimal for array containing negatives also.
    TC : O(N^2) - Worst Case, unordered map - O(N), ordered map - O(NlogN)
    SC : O(N)
*/
int better(vector<int> &arr, long long k){
    int maxLen = 0;
    long long sum = 0;
    map<long long, int> preSum;
    for(int i=0; i<arr.size(); i++){
        sum = sum + arr[i];
        if(sum == k){
            maxLen = max(maxLen, i+1); //if sum matches with k, check len max
        }
        long long rem = sum - k; //otherwise find remainder
        if(preSum.find(rem) != preSum.end()){ //if remainder exists in the presum matrix
            int len = i-preSum[rem]; //find length by subtracting position of presum from i.
            maxLen = max(maxLen, len); //check maximum
        }
        if(preSum.find(sum) == preSum.end()){ //if sum does not exist in the hash map add it to the hash map
            preSum[sum] = i; //add values to presum hash map
        }
    }
    return maxLen;
}

/*
    Optimal Solution using 2 pointer approach and greedy algorithm
    TC : O(2N)
    SC : O(1)
*/
int optimal(vector<int> arr, long long k){
    int maxLen = 0;
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int n = arr.size();
    while(right < n){
        while(sum > k && left <= right){
            sum = sum - arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right<n){
            sum = sum + arr[right];
        }
    }
    return maxLen;
}

int main(){
    vector<int> arr = {1, 2, 3, 1, 1, 1, 3, 4, 2, 3};
    long long k = 6;
    // int ans = brute(arr, k);
    // int ans = better(arr, k);
    int ans = optimal(arr, k);
    cout << ans << endl;
    return 0;
}