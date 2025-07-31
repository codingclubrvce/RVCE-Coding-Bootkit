#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<char>>& adj){
    vis[x][y]=1;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    for(int i = 0; i<4; i++){
        int xi = x + dx[i];
        int yi = y + dy[i];
        if(xi>=0 && yi>=0 && xi<adj.size() && yi<adj[0].size()){
            if(adj[xi][yi]=='O' && vis[xi][yi]==0){
                dfs(xi, yi, vis, adj);
            }
        }
    }
}

int main(){
    vector<vector<char>> adj = {
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'O', 'O'},
    };
    int n = adj.size();
    int m = adj[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++){
        if(adj[i][0]=='O'){
            dfs(i, 0, vis, adj);
        }
        if(adj[i][m-1]=='O'){
            dfs(i, m-1, vis, adj);
        }
    }
    for(int i = 0; i<m; i++){
        if(adj[0][i]=='O'){
            dfs(0, i, vis, adj);
        }
        if(adj[n-1][i]=='O'){
            dfs(n-1, i, vis, adj);
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(adj[i][j]=='O' && vis[i][j]==0){
                adj[i][j] = 'X';
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}