/**
 * Spiral Traversal in a matrix
 *  1  2  3  4  5  6
 * 20 21 22 23 24  7
 * 19 32 33 34 25  8
 * 18 31 36 35 26  9
 * 17 30 29 28 27 10 
 * 16 15 14 13 12 11
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> ans;
    vector<vector<int>> nums = {{1, 2, 3, 4, 5, 6}, {20, 21, 22, 23, 24, 7}, {19, 32, 33, 34, 25,  8}, {18, 31, 36, 35, 26,  9}, {17, 30, 29, 28, 27, 10 }, {16, 15, 14, 13, 12, 11}};
    int n = nums.size(); //number of rows
    int m = nums[0].size(); //number of columns
    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n-1;
    while(top <= bottom && left <= right){
        //RIGHT
        for(int i = left; i<=right; i++){
            ans.push_back(nums[top][i]);
        }
        top++;
        //BOTTOM
        for(int i = top; i<=bottom; i++){
            ans.push_back(nums[i][right]);
        }
        right--;
        //LEFT
        if(top<=bottom){
            for(int i = right; i>=left; i--){
                ans.push_back(nums[bottom][i]);
            }
            bottom--;
        }
        //TOP
        if(left<=right){
            for(int i = bottom; i>=top; i--){
                ans.push_back(nums[i][left]);
            }
            left++;
        }
    }
    for(int i = 0; i<m*n; i++){
        cout << ans[i] << " ";
    }
}