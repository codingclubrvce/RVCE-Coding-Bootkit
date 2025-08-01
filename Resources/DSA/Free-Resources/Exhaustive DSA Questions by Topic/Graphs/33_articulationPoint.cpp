#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<int>& mark){
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    int child = 0;
    for(auto it:adj[node]){
        if(it == parent){
            continue;
        }
        if(!vis[it]){
            dfs(it, node, vis, adj, tin, low, mark);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tin[node] && parent != -1){
                mark[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }
    if(child>1 && parent==-1){
        mark[node] = 1;
    }
}

int main(){
    vector<vector<int>> adj = {
        {1, 2, 3},
        {0},
        {0, 3, 4, 5},
        {0, 2},
        {2, 6},
        {2, 6},
        {4, 5}
    };
    vector<int> tin(adj.size(), 0);
    vector<int> low(adj.size(), 0);
    vector<int> vis(adj.size(), 0);
    vector<int> mark(adj.size(), 0);
    for(int i = 0; i<adj.size(); i++){
        if(vis[i] == false){
            dfs(i, -1, vis, adj, tin, low, mark);
        }
    }
    cout << "Articulation points: ";
    for(int i = 0; i<mark.size(); i++){
        if(mark[i]) cout << i << " ";
    }
    return 0;
}