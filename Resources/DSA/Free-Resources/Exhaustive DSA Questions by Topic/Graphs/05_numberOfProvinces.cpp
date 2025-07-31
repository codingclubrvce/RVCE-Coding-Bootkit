#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>>& list, vector<int>& vis){
    vis[i]=1;
    for(auto node: list[i]){
        if(!vis[node]){
            dfs(node, list, vis);
        }
    }
}

int numberOfProvinces(vector<vector<int>>& adj, int v){
    vector<vector<int>> list(v);
    for(int i = 0;i<v;i++) {
        for(int j = 0;j<v;j++) {
            if(adj[i][j] == 1 && i != j) {
                list[i].push_back(j); 
                list[j].push_back(i); 
            }
        }
    }
    vector<int> vis(v, 0);
    int c = 0;
    for(int i = 0; i<v; i++){
        if(!vis[i]){
            dfs(i, list, vis);
            c++;
        }
    }
    return c;
}

int main(){
    vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    cout << numberOfProvinces(adj, 3) << endl;
    return 0;
}