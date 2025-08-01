#include <bits/stdc++.h>
using namespace std;

void traverse(vector<vector<int>>& adj, int vis[], int node, vector<int> &dfs){
    dfs.push_back(node);
    vis[node] = 1;
    for(auto i: adj[node]){
        if(!vis[i]){
            traverse(adj, vis, i, dfs);
        }
    }
    
}

int main(){
    vector<vector<int>> adj = {{}, {2, 5, 6}, {1, 3, 5}, {2, 4, 5}, {3, 5}, {1, 2, 3, 4}, {1}};
    int n = 6;
    vector<int> dfs;
    int vis[n+1] = {0};
    traverse(adj, vis, 1, dfs);
    for(auto i: dfs){
        cout << i << " ";
    }
    return 0;
}