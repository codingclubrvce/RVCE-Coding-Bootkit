#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<pair<int, int>>> adj = {
        {{1, 4}, {2, 4}},
        {{0, 4}, {2, 2}},
        {{0, 4}, {1, 2}, {3, 3}, {4, 1}, {5, 6}},
        {{2, 3}, {5, 2}},
        {{2, 1}, {5, 3}},
        {{3, 2}, {4, 3}}
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    vector<int> dist(adj.size(), 1e8);
    dist[0] = 0;
    while(!q.empty()){
        auto p = q.top();
        int d = p.first;
        int n = p.second;
        q.pop();
        for(auto it:adj[n]){
            int wt = it.second;
            int node = it.first;
            if(dist[node] > d+wt){
                dist[node] = d+wt;
                q.push({dist[node], node});
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