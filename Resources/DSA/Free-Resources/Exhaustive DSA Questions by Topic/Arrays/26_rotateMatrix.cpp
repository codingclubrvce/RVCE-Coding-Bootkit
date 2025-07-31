/**
 * Rotating matrix by 90 degrees.
 * Input - 
 * 1   2  3  4
 * 5   6  7  8 
 * 9  10 11 12
 * 13 14 15 16
 * Output -
 * 13  9 5 1
 * 14 10 6 2
 * 15 11 7 3
 * 16 12 8 4
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * Brute force transformation
 *     TC : O(N^2)
 *     SC : O(N^2)
*/
vector<vector<int>> brute(vector<vector<int>>& nums){
    vector<vector<int>> ans = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    for(int i = 0; i<nums.size(); i++){
        for(int j = 0; j<nums.size(); j++){
            ans[j][nums.size()-1-i] = nums[i][j];
        }
    }
    return ans;
}
/**
 * Optimal Solution - transpose and reverse each row
 *     TC : O(N^2)
 *     SC : O(1)
*/
vector<vector<int>> optimal(vector<vector<int>>& nums){
    for(int i = 0; i<=nums.size()-2; i++){
        for(int j = i+1; j<=nums.size()-1; j++){
            swap(nums[i][j], nums[j][i]);
        }
    }
    for(int i = 0; i<nums.size(); i++){
        reverse(nums[i].begin(), nums[i].end());
    }
    return nums;
}

int main(){
    vector<vector<int>> nums = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> ans = optimal(nums);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans.size(); j++){
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }
}