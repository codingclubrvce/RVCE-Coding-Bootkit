#include <bits/stdc++.h>
using namespace std;

void bfs(int i, int j, vector<vector<int>>& a, vector<vector<int>>& vis){
    vis[i][j] = 1;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        for(int k = 0; k<4; k++){
            int xi = p.first + dx[k];
            int yi = p.second + dy[k];
            if(xi>=0 && yi>=0 && xi<a.size() && yi<a[0].size()){
                if(a[xi][yi] == 1){
                    if(!vis[xi][yi]){
                        vis[xi][yi] = 1;
                        q.push({xi, yi});
                    }
                }
            }
        }
    }
}

int main(){
    vector<vector<int>> a = {
        {1, 1, 1, 0, 0},
        {1, 1, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1}
    };
    int ans = 0;
    vector<vector<int>> vis(a.size(), vector<int>(a[0].size(), 0));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j] == 1 && !vis[i][j]){
                bfs(i, j, a, vis);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}