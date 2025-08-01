/**
 * Pascals Triangle - O(N^2)
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 * 1 4 6 4 1
*/

#include<iostream>
#include<vector>
using namespace std;

/**
 * The logic -
 * 5th row is nothing but 1, (4/1), (4x3)/(1x2), (4x3x2)/(1x2x3), (4x3x2x1)/(1x2x3x4)
 * So each time we multiple the previous element by (row - col) and divide by the col
*/

// TC : O(N)
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col = 1; col<row; col++){
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

// TC : O(N)
vector<vector<int>> pascal(int n){
    vector<vector<int>> ans;
    for(int i = 1; i<=n; i++ ){
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main(){
    int row = 6;
    vector<vector<int>> p = pascal(row); //stores answer matrix
    //printing the answer matrix
    for(int i = 0; i<p.size(); i++){
        for(int j = 0; j<p[i].size(); j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}