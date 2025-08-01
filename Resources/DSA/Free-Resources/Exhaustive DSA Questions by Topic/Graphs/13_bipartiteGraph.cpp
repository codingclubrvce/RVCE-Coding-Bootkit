#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int colour, vector<int>& vis, vector<vector<int>> adj){
    vis[i] = colour;
    for(auto it:adj[i]){
        if(vis[it]==-1){
            if(dfs(it, !colour, vis, adj) == false){
                return false;
            }
        }
        else if(vis[it]==colour){
            return false;
        }
    }
    return true;
}

bool bfs(int i, int colour, vector<int>&vis, vector<vector<int>> adj){
    queue<int> q;
    vis[i] = colour;
    q.push(i);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto n:adj[f]){
            if(vis[n]==-1){
                vis[n] = !vis[f];
            }
            else if(vis[n]==vis[f]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> adj = {
        {1},
        {0, 2},
        {1, 3, 8},
        {2, 4},
        {3, 5},
        {4, 6, 9},
        {5, 7},
        {6},
        {2, 9},
        {5, 8}
    };
    int n = adj.size();
    vector<int> vis(n, -1);
    for(int i = 0; i<n; i++){
        if(vis[i]==-1){
            if(dfs(i, 0, vis, adj) == false){
                cout << "Not bipartite" << endl;
                return 0;
            }
        }
    }
    cout << "Bipartite Graph" << endl;
    return 0;
}