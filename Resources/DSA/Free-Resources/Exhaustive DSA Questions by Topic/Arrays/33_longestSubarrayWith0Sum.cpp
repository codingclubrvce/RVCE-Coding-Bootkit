/**
 * Length of Longest Subarray with Sum 0
 * arr = [9, -3, 3, -1, 6, -5]
 * (-3, 3), (-1, 6, -5), (-3, 3, -1, 6, -5)
 * hence answer is 5
*/

#include<vector>
#include<iostream>
using namespace std;

int brute(vector<int> nums){
    int sum = 0;
    int maxi = INT_MIN;
    for(int i = 0; i<nums.size(); i++){
        sum = sum + nums[i];
        if(sum == 0){
            maxi = max(i+1, maxi);
        }
    }
    return maxi;
}

int main(){
    vector<int> nums = {9, -3, 3, -1, 6, -5};
    cout << brute(nums) << endl;
    return 0;
}