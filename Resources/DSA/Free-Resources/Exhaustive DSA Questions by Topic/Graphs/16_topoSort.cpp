#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> adj, vector<int>& vis, stack<int>& st){
    vis[i] = 1;
    for(auto it:adj[i]){
        if(!vis[it]) dfs(it, adj, vis, st);
    }
    st.push(i);
}

int main(){
    vector<vector<int>> adj = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}
    };
    stack<int> st;
    vector<int> vis(adj.size(), 0);
    for(int i = 0; i<adj.size(); i++){
        if(!vis[i]) dfs(i, adj, vis, st);
    }
    cout << "Topological Order: ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}