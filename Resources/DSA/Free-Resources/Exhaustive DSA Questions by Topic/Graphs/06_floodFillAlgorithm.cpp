#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> img, int sr, int sc, int newc, int inic, vector<vector<int>>& ans, vector<int> dx, vector<int> dy){
    ans[sr][sc] = newc;
    for(int i = 0; i<4; i++){
        int nr = sr + dx[i];
        int nc = sc + dy[i];
        if(nr>=0 && nc>=0 && nr<img.size() && nc<img[0].size() && img[nr][nc]==inic && ans[nr][nc]!=newc){
            dfs(img, nr, nc, newc, inic, ans, dx, dy);
        }
    }
}

int main(){
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    vector<vector<int>> img = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    vector<vector<int>> ans = img;
    cout << "Before flood fill: " << endl;
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    int sr = 1, sc = 1, newc = 2, inic = 1;
    dfs(img, sr, sc, newc, inic, ans, dx, dy);
    cout << "After flood fill: " << endl;
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}