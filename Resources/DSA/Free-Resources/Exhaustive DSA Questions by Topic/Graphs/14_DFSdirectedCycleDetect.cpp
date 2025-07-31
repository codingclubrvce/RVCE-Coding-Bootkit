#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<int>& vis, vector<int>& path, vector<vector<int>>& adj){
    vis[i] = 1;
    path[i] = 1;
    for(auto v:adj[i]){
        if(!vis[v]){
            if(dfs(v, vis, path, adj) == true) return true;
        }
        else if(vis[v] && path[v]) return true;
    }
    path[i] = 0;
    return false;
}

int main(){
    vector<vector<int>> adj = {
        {},
        {2},
        {3},
        {4, 7},
        {5},
        {6},
        {},
        {5},
        {9},
        {10},
        {8}
    };
    vector<int> vis(adj.size(), 0);
    vector<int> path(adj.size(), 0);
    for(int i = 0; i<adj.size(); i++){
        if(!vis[i]){
            if(dfs(i, vis, path, adj)==true){
                cout << "Cycle Detected" << endl;
                return 0;
            }
        }
    }
    cout << "No Cycle Detected" << endl;
    return 0;
}