/**
 * Counting the number of subarrays with sum equal to K
 * arr[] = [1, 2, 3, -3, 1, 1, 1, 4, 2, -3]
 * K = 3
 * Answer = 3
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

/**
 * Brute force solution
 * TC : O(N^3)
 * SC : O(1)
*/
int brute(vector<int> nums, int k){
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            int sum = 0;
            for(int k = i; k<=j; k++){
                sum = sum + nums[k];
            }
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

/**
 * Better Solution
 * TC : O(N^2)
 * SC : O(1)
*/
int better(vector<int> nums, int k){
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        int sum = 0;
        for(int j = i; j < nums.size(); j++){
            sum = sum + nums[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

/**
 * Optimal Solution - Prefix Sum Concept
 * TC : O(NlogN)
 * SC : O(N)
*/
int optimal(vector<int> nums, int k){
    map<int, int> mpp;
        mpp[0] = 1;
        int presum = 0;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            presum =presum + nums[i];
            int rem = presum - k;
            count = count + mpp[rem];
            mpp[presum]++;
        }
        return count;
}

int main(){
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    int ans = optimal(nums, k);
    cout << ans;
}