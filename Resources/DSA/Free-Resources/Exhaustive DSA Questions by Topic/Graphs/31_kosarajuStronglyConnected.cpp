#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
    vis[i] = 1;
    for(auto v:adj[i]){
        if(!vis[v]){
            dfs(v, adj, vis, st);
        }
    }
    st.push(i);
}

void dfs(int i, vector<vector<int>>& adj, vector<int>& vis){
    vis[i] = 1;
    for(auto v:adj[i]){
        if(!vis[v]){
            dfs(v, adj, vis);
        }
    }
}

int main(){
    vector<vector<int>> adj = {
        {1},
        {2},
        {0, 3},
        {4}, 
        {5, 7},
        {6},
        {4, 7},
        {}
    };
    stack<int> st;
    vector<int> vis(adj.size(), 0);
    // Topo Sorting
    for(int i = 0; i<adj.size(); i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }
    // Edge Reversal
    vector<vector<int>> g(adj.size());
    for(int i = 0; i<adj.size(); i++){
        for(int j = 0; j<adj[i].size(); j++){
            g[adj[i][j]].push_back(i);
        }
    }
    // Refill vis with all zeroes
    for(int i = 0; i<vis.size(); i++){
        vis[i] = 0;
    }
    // Count strongly connected components
    int sc = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            sc++;
            dfs(node, g, vis);
        }
    }
    cout << "Number of strongly connected components: " << sc << endl;
    return 0;
}