#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> edges = {{2, 1, 2}, {3, 2, 3}, {3, 2, 4}, 
                                {4, 1, 5}, {1, 1, 4}, {5, 3, 4}, 
                                {7, 2, 6}, {8, 3, 6}, {9, 4, 5}};
    vector<vector<pair<int, int>>> adj(7);
    for(int i = 0; i<edges.size(); i++){
        adj[edges[i][1]].push_back({edges[i][2], edges[i][0]});
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    int sum = 0;
    vector<pair<int, int>> mst;
    vector<int> vis(7, 0);
    pq.push({0, 1, -1});
    while(!pq.empty()){
        auto [wt, node, parent] = pq.top();
        pq.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        if(parent != -1){
            mst.push_back({node, parent});
            sum+=wt;
        }
        for(auto &[adjNode, adjWt]:adj[node]){
            if(!vis[adjNode]){
                pq.push({adjWt, adjNode, node});
            }
        }
    }
    cout << "Sum of MST Edges: " << sum << endl;
    cout << "MST: " << endl;
    for(int i = 0; i<mst.size(); i++){
        cout << "(" << mst[i].first << ", " << mst[i].second << ")" << endl;
    }
    return 0;
}