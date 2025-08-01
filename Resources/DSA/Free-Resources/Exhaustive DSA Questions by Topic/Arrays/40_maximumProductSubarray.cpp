/**
 * MAXIMUM PRODUCT SUBARRAY
*/

#include<iostream>
#include<vector>
using namespace std;

/**
 * Brute - 3 Nested Loops
 * TC : O(N^3)
 * SC : O(1)
*/

/**
 * Better - 2 Nested Loops
 * TC : O(N^2)
 * SC : O(1)
*/
int better(vector<int> nums){
    int result = nums[0];
    for(int i = 0; i<nums.size(); i++){
        int prod = nums[i];
        for(int j = i+1; j<nums.size(); j++){
            result = max(result, prod);
            prod = prod * nums[j];
        }
        result = max(result, prod);
    }
    return result;
}

int optimal(vector<int> nums){
    int pre = 1;
    int suf = 1;
    int maxi = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        if(pre == 0){
            pre = 1;
        }
        if(suf == 0){
            suf = 1;
        }
        pre = pre*nums[i];
        suf = suf*nums[nums.size()-i-1];
        maxi = max(maxi, max(suf, pre));
    }
    return maxi;
}

int main() {
    vector<int> nums = {7, 1, -1, 3, 0, 1, 2, 0, -1, -2, 7};
    cout << "The maximum product subarray: " << optimal(nums);
    return 0;
}