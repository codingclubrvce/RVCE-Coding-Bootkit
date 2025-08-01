#include <bits/stdc++.h>
using namespace std;

vector<int> traverse(vector<vector<int>> adj, int n){
    int vis[n+1] = {0};
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    vector<int> bfs;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        bfs.push_back(n);
        for(auto i: adj[n]){
            if(!vis[i]){
                q.push(i);
                vis[i] = 1;
            }
        }
    }   
    return bfs;
}

int main(){
    vector<vector<int>> adj = {{}, {2, 5}, {1, 5, 3}, {2, 4, 5}, {3, 5}, {1, 2, 3, 4}};
    int n = 5;
    vector<int> bfs = traverse(adj, n);
    for(auto i: bfs){
        cout << i << " ";
    }
    return 0;
}