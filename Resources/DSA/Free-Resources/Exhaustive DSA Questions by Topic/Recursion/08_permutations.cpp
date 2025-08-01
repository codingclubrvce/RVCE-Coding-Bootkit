#include<iostream>
#include<vector>
using namespace std;

/*
    FIRST APPROACH
        TC : O(N!XN)
        SC : O(N+N)
*/
void funcForPermutation(vector<int> ds, vector<int> nums, int freq[], vector<vector<int>>& ans){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int i = 0; i<nums.size(); i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            funcForPermutation(ds, nums, freq, ans);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

/*
    SECOND APPROACH
        TC : O()
        SC : O()
*/
 void recursive(int index, vector<int> &nums, vector<vector<int>> &ans){ //initially pass index as 0
    if(index == nums.size()){ 
        ans.push_back(nums);
        return;
    }
    for(int i = index; i<nums.size(); i++){
        swap(nums[index], nums[i]);
        recursive(index+1, nums, ans);
        swap(nums[index], nums[i]);
    }
}