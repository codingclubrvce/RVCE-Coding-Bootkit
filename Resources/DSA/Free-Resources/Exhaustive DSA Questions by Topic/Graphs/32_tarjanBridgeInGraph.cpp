#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low){
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    for(auto it:adj[node]){
        if(it == parent){
            continue;
        }
        if(!vis[it]){
            dfs(it, node, vis, adj, tin, low);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node]){
                cout << "Bridge " << it << " and " << node << endl;
            }
        }
        else{
            low[node] = min(low[node], low[it]);
        }
    }
}

int main(){
    vector<vector<int>> adj = {
        {1},
        {0, 2, 4},
        {1, 3},
        {2, 4},
        {1, 5},
        {4, 6},
        {7, 9},
        {6, 8},
        {7, 9, 10},
        {6, 8},
        {8, 11, 12},
        {10, 12},
        {10, 11}
    };
    vector<int> tin(adj.size(), 0);
    vector<int> low(adj.size(), 0);
    vector<int> vis(adj.size(), 0);
    for(int i = 0; i<adj.size(); i++){
        if(vis[i] == false){
            dfs(i, -1, vis, adj, tin, low);
        }
    }
    return 0;
}