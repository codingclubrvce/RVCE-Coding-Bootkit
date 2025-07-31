/*
    Leaders in an array are elements which are greater than all elements to their right.
    Suppose arr[] = [10, 22, 12, 3, 0, 6]
    ans[] = [22, 12, 6]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> brute(vector<int> nums){
    // TC : O(N^2) - nearly
    vector<int> ans;
    for(int i = 0; i<nums.size(); i++){
        bool leader = true;
        for(int j = i+1; j<nums.size(); j++){
            if(nums[j] > nums[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

vector<int> optimal(vector<int> nums){
    // TC : O(N)
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = nums.size()-1; i>=0; i--){
        if(nums[i]>maxi){
            ans.push_back(nums[i]);
            maxi = nums[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> nums = {10, 22, 12, 3, 0, 6};
    vector<int> ans = optimal(nums);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}