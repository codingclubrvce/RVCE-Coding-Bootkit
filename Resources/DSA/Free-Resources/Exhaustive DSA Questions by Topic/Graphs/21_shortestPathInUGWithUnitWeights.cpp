#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> adj = {
        {1, 3},
        {0, 2, 3},
        {1, 6},
        {0, 1, 4},
        {3, 5},
        {4, 6},
        {2, 5, 7},
        {6},
        {}
    };
    queue<int> q;
    q.push(0);
    vector<int> dist(adj.size(), 1e8);
    dist[0] = 0;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        for(auto it:adj[p]){
            if(dist[it]>dist[p]+1){
                dist[it] = dist[p]+1;
                q.push(it);
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