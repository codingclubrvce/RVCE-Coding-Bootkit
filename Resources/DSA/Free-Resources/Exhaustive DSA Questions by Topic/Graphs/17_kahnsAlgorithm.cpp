#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> adj = {
        {},       // 0
        {},       // 1
        {3},      // 2 -> 3
        {1},      // 3 -> 1
        {0, 1},   // 4 -> 0, 1
        {0, 2}    // 5 -> 0, 2
    };
    vector<int> in(adj.size(), 0);
    vector<int> vis(adj.size(), 0);
    queue<int> q;
    for(auto v:adj){
        for(auto u:v){
            in[u]++;
        }
    }
    for(int i = 0; i<in.size(); i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        topo.push_back(p);
        for(auto it:adj[p]){
            in[it]--;
            if(in[it] == 0){
                q.push(it);
            }
        }
    }
    cout << "Topological Order: ";
    for(int i = 0; i<topo.size(); i++){
        cout << topo[i] << " ";
    }
    return 0;
}