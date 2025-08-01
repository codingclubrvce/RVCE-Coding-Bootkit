/**
 * Sum of triplets is 0
 * Should be unique triplets
 * i != j != k
*/

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

/**
 * BRUTE - 3 Pointer
 * Use set to store sorted triplet in order to avoid duplicates
 * TC - O(N^3 log(number of triplets))
 * SC - 2 x O(number of triplets)
*/
vector<vector<int>> brute(vector<int> nums){
    int n = nums.size();
    set<vector<int>> st; // SC - O(number of triplets)
    for(int i = 0; i<n; i++){ 
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> result (st.begin(), st.end()); // SC - O(number of triplets)
    return result;
}

/**
 * BETTER - Using Hash Set
 * Empty the hash set after each iteration in 'i' and add elements to hash set as we iterate over 'j'
 * TC - O(N^2 log M), where M varies
 * SC - O(N) + 2 x O(numbers of triplets)
*/
vector<vector<int>> better(vector<int> nums){
    int n = nums.size();
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        set<int> hash;
        for(int j = i+1; j < n; j++){
            int third = -(nums[i] + nums[j]);
            if(hash.find(third) != hash.end()){ //check if third elem is present
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hash.insert(nums[j]);
        }
    }
    vector<vector<int>> result (st.begin(), st.end());
    return result;
}

/**
 * OPTIMAL - 2 Pointer Approach
 * TC - O(N^2) + O(NlogN)
 * SC - O(number of triplete)
*/
vector<vector<int>> optimal(vector<int> nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for(int i = 0; i < nums.size(); i++){
        if(i>0 && nums[i] == nums[i-1]) // if i is the same as before, move one ahead
            continue;
        int j = i+1; //just after i
        int k = nums.size() -1; // last element
        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0)
                j++; //since it is sorted, we need to move towards positive if sum is negative
            else if(sum > 0)
                k--; //since it is sorted, we need to move towards negative if sum is positive
            else{
                vector<int> temp = {nums[i], nums[j], nums[k]};
                    result.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1]) // if j is the same as before, move one ahead
                    j++;
                while(j<k && nums[k] == nums[k+1]) // if k is the same as before, move one ahead
                    k--;
                
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2};
    vector<vector<int>> ans = optimal(nums);
    for(int i = 0; i<ans.size(); i++){
        cout << "[" << ans[i][0] << "," << ans[i][1] << "," << ans[i][2] << "]" << endl;
    }
    return 0;
}