#include <bits/stdc++.h>
using namespace std;

void dfs(int i, const vector<vector<pair<int, int>>>& adj, vector<int>& vis, stack<int>& st) {
    vis[i] = 1;
    for (auto it : adj[i]) {
        int v = it.first;
        if (!vis[v]) dfs(v, adj, vis, st);
    }
    st.push(i);
}

int main() {
    vector<vector<pair<int, int>>> adj = {
        {{1, 2}},
        {},
        {},
        {},
        {{0, 3}, {2, 1}},
        {{4, 1}},
        {{4, 2}, {5, 3}}
    };
    stack<int> st;
    vector<int> vis(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++) {
        if (!vis[i]) dfs(i, adj, vis, st);
    }
    vector<int> dist(adj.size(), 10000);
    dist[6] = 0;
    while (!st.empty()) {
        int t = st.top();
        st.pop();
        for(auto it:adj[t]){
            if(dist[t]+it.second < dist[it.first]){
                dist[it.first] = dist[t]+it.second;
            }
        }
    }
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] == 10000)
            cout << "Node " << i << ": INF" << endl;
        else
            cout << "Node " << i << ": " << dist[i] << endl;
    }
    return 0;
}