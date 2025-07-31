#include <bits/stdc++.h>
using namespace std;

bool detect(vector<vector<int>> adj, int src){
    vector<int> vis(adj.size());
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto n:adj[node]){
            if(!vis[n]){
                vis[n] = 1;
                q.push({n, node});
            }
            else if(parent != n) return true;
        }
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
    if(detect(adj, 0)) cout << "Cycle Exists" << endl;
    else cout << "Cycle Does Not Exist" << endl;
    return 0;
}