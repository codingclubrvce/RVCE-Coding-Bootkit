#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bruteforce(){
    //generate all permutations, in sorted order, do linear search to find next permutation
    //TC : O(N!xN)
}

vector<int> better(vector<int> nums){
    //using STL
    next_permutation(nums.begin(), nums.end());
    return nums;
}

vector<int> optimal(vector<int> nums){
    //TC : O(3N)
    //SC : O(1)
    int ind = -1;
    int n = nums.size();
    for(int i = n-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(nums.begin(), nums.end());
    }
    else{
        for(int j = n-1; j>=ind; j--){
            if(nums[j]>nums[ind]){
                swap(nums[j], nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1, nums.end());
    }
    return nums;
}

int main(){
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = optimal(nums);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}