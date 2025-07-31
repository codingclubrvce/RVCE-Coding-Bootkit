/**
 * arr[] = [1,0,-1,0,-2,2], target = 0
 * Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * arr[] = [4,3,3,4,4,2,1,2,1,1], target = 9
 * Result: [[1,1,3,4],[1,2,2,4],[1,2,3,3]]
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/**
 * Brute Force Approach - Nested Loops
 * TC : O(N^4)
 * SC : O(2 x No. of quadruplets)
*/
vector<vector<int>> brute(vector<int> nums, int target){
    set<vector<int>> st;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                for(int l = k+1; l < n; l++){
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(target == sum){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> result = {st.begin(), st.end()};
    return result;
}

/**
 * Better Solution - Hashing
 * TC : O(N^3)
 * SC : O(2 x No. of quadruplets) + O(N) for the hashSet
*/
vector<vector<int>> better(vector<int> nums, int target){
    set<vector<int>> st;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            set<int> hashSet;
            for(int k = j+1; k < n; k++){
                int req = target - nums[i] - nums[j] - nums[k];
                if(hashSet.find(req) != hashSet.end()){
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)req};
                    sort(temp.begin(), temp.end());
                        st.insert(temp);
                }
                hashSet.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> result = {st.begin(), st.end()};
    return result;
}

/**
 * OPTIMAL Solution is much similar to the optimal Solution for three sum problem where we will define 2 pointers to be fixed and the other two will be moving. If the sum is greater than target then come closer, else move away. The array has to be sorted initially.
 * TC : O(N^3)
 * SC : O(1)
*/
vector<vector<int>> optimal(vector<int> nums, int target){
    int n = nums.size();
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        //skipping duplicates
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
        for(int j = i+1; j<n; j++){
            if(j>i+1 && nums[j] == nums[j-1]){
                continue;
            }
            int k = j+1;
            int l = n-1;
            while(k<l){
                if(nums[i] + nums[j] + nums[k] + nums[l] > target){
                    l--;
                }
                else if(nums[i] + nums[j] + nums[k] + nums[l] < target){
                    k++;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    result.push_back(temp);
                    l--;
                    k++;
                    while(k<l && nums[k] == nums[k-1]){
                        k++;
                    }
                    while(k<l && nums[l] == nums[l+1]){
                        l--;
                    }
                }
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums = {4,3,3,4,4,2,1,2,1,1};
    int target = 9;
    vector<vector<int>> ans = optimal(nums, target);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
    }
    return 0;
}