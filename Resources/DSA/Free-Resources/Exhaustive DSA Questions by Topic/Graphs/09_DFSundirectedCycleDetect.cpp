#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, int parent, vector<vector<int>> adj, vector<int>& vis){
    vis[src] = 1;
    for(auto node:adj[src]){
        if(vis[node]==0){
            if(dfs(node, src, adj, vis)){
                return true;
            }
        }
        else if(node != parent) return true;
    }
    return false;
}

int main(){
    vector<vector<int>> adj = {
        {1},
        {2, 3},
        {1, 5},
        {1, 4, 6},
        {3},
        {2, 7},
        {3, 7},
        {5, 6}
    };
    vector<int> vis(adj.size(), 0);
    if(dfs(0, -1, adj, vis)) cout << "Cycle Exists" << endl;
    else cout << "Cycle Does Not Exist" << endl;
    return 0;
}