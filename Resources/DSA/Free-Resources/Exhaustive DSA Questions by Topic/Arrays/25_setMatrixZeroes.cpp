/*
    given matrix is
    1 1 1 1
    1 0 0 1
    1 1 0 1 
    1 1 1 1
    make all elements zero which have a zero in the row or column
    1 0 0 1
    0 0 0 0
    0 0 0 0
    1 0 0 1
*/

#include<vector>
#include<iostream>
using namespace std;

// column = arr[][0]
// row = arr[0][]

void markRow(int i, int m, vector<vector<int>>& nums){
    for(int x = 0; x<m; x++){
        if(nums[i][x] == 1){
            nums[i][x] = -1;
        }
    }
}
void markColumn(int j, int n, vector<vector<int>>& nums){
    for(int x = 0; x<n; x++){
        if(nums[x][j] == 1){
            nums[x][j] = -1;
        }
    }
}

vector<vector<int>> brute(vector<vector<int>>& nums){
    // TC : O((nxm)x(n+m)+(nxm)) nearly N^3
    // SC : O(1)
    int n = nums.size();
    int m = nums[0].size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(nums[i][j]==0){
                markRow(i, m, nums); //n
                markColumn(j, n, nums); //m
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(nums[i][j] == -1){
                nums[i][j] = 0;
            }
        }
    }
    return nums;
}

vector<vector<int>> better(vector<vector<int>>& nums){
    // TC : O(2xnxm)
    // SC : O(m+n)
    int n = nums.size();
    int m = nums[0].size();
    vector<int> col(m, 0);
    vector<int> row(n, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(nums[i][j] == 0){
                col[j] = 1;
                row[i] = 1;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(row[i] || col[j]){
                nums[i][j] = 0;
            }
        }
    }
    return nums;
}

vector<vector<int>> optimal(vector<vector<int>>& nums){
    // TC : O(2xnxm) nearly N^2
    // SC : O(1)
    int col0 = 1;
    int n = nums.size();
    int m = nums[0].size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(nums[i][j] == 0){
                nums[i][0] = 0;
                if(j!=0){
                    nums[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j<m; j++){
            if(nums[i][j] != 0){
                if(nums[0][j] == 0 || nums[i][0] == 0){
                    nums[i][j] = 0;
                }
            }
        }
    }
    if(nums[0][0] == 0){
        for(int j = 0; j<m; j++){
            nums[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i = 0; i<n; i++){
            nums[i][0] = 0;
        }
    }
    return nums;
}

int main(){
    vector<vector<int>> nums= {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};
    cout << "Original Matrix" << endl;
    for(int i = 0; i<nums.size(); i++){
        for(int j = 0; j<nums[0].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Modified Matrix" << endl;
    vector<vector<int>> ans = optimal(nums);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}