#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<int>& vis, vector<vector<int>> adj, vector<int>& path, vector<int>& check){
    vis[i] = 1;
    path[i] = 1;
    check[i] = 0;
    for(auto it:adj[i]){
        if(!vis[it]){
            if(dfs(it, vis, adj, path, check) == true){
                check[i] = 0;
                return true;
            }
        }
        else if(path[it]){
            check[i] = 0;
            return true;
        }
    }
    check[i] = 1;
    path[i] = 0;
    return false;
}

void bfs(int i, vector<vector<int>> adj, vector<int>& check){
    vector<vector<int>> r(adj.size());
    for(int i = 0; i<adj.size(); i++){
        for(int j = 0; j<adj[i].size(); j++){
            r[adj[i][j]].push_back(i);
        }
    }
    vector<int> in(adj.size(), 0);
    for(auto v:r){
        for(auto u:v){
            in[u]++;
        }
    }
    queue<int> q;
    for(int i = 0; i<in.size(); i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int p = q.front();
        q.pop();
        check[p] = 1;
        for(auto it:r[p]){
            in[it]--;
            if(in[it] == 0){
                q.push(it);
            }
        }
    }
}

int main(){
    vector<vector<int>> adj = {
        {1, 2},
        {3},
        {5},
        {0},
        {5},
        {},
        {},
        {0}
    };
    vector<int> vis(adj.size(), 0);
    vector<int> path(adj.size(), 0);
    vector<int> check(adj.size(), 0);
    // for(int i = 0; i<adj.size(); i++){
    //     if(!vis[i]) dfs(i, vis, adj, path, check);
    // }
    for(int i = 0; i<adj.size(); i++){
        if(!vis[i]) bfs(i, adj, check);
    }
    cout << "Safe Nodes: ";
    for(int i = 0; i<adj.size(); i++){
        if(check[i]==1){
            cout << i << " ";
        }
    }
    return 0;
}