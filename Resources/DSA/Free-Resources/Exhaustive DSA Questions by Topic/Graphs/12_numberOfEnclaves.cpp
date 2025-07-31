#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> adj = {
        {1, 0, 0, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
    };
    int n = adj.size();
    int m = adj[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(adj[i][j]==1 && (i==0 || j==0 || i==n-1 || j==m-1)){
                vis[i][j]=1;
                q.push({i, j});
            }
        }
    }
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    while(!q.empty()){
        auto p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        for(int i = 0; i<4; i++){
            int xi = x + dx[i];
            int yi = y + dy[i];
            if(xi>=0 && yi>=0 && xi<n && yi<m && adj[xi][yi]==1 && !vis[xi][yi]){
                vis[xi][yi] = 1;
                q.push({xi, yi});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(adj[i][j]==1 && vis[i][j]==0){
                ans++;
            }
        }
    }
    cout << "Number of enclaves: " << ans << endl;
    return 0;
}