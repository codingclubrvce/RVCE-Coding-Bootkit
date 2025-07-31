#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> modify(vector<vector<int>>& adj){
    vector<vector<int>> vis(adj.size(), vector<int>(adj.size(), 0));
    vector<vector<int>> dist(adj.size(), vector<int>(adj.size(), 0));
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i<adj.size(); i++){
        for(int j = 0; j<adj[0].size(); j++){
            if(adj[i][j] == 1){
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.first.first;
        int y = p.first.second;
        dist[x][y] = p.second;
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};
        for(int i = 0; i<4; i++){
            int xi = x+dx[i];
            int yi = y+dy[i];
            if(xi>=0 && yi>=0 && xi<adj.size() && yi<adj[0].size()){
                if(!vis[xi][yi]){
                    vis[xi][yi] = 1;
                    q.push({{xi, yi}, p.second+1});
                }
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> adj = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 1}
    };
    for(int i = 0; i<adj.size(); i++){
        for(int j = 0; j<adj[0].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    vector<vector<int>> ans = modify(adj);
    cout << "Distance matrix: " << endl;
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}