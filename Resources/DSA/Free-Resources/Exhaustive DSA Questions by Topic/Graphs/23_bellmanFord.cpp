#include <bits/stdc++.h>
using namespace std;

int main(){
    // vector<vector<int>> adj = {
    //     {{0, 1, 5}}, {1, 2, -2}, {1, 5, -3}, {2, 4, 3}, {3, 2, 6}, {3, 4, -2}, {5, 3, 1}};
    vector<vector<int>> adj = {{0, 1, -2}, {1, 2, -1}, {2, 0, 2}};
    vector<int> dist(3, 1e9);
    dist[0] = 0;
    for(int i = 0; i<adj.size()-1; i++){
        for(auto it:adj){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dist[u] != 1e9 && dist[u]+w<dist[v]){
                dist[v] = dist[u] + w;
            }
        }
        
    }
    for(auto it:adj){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dist[u] != 1e9 && dist[u]+w<dist[v]){
                cout << "Negative Cycle Detected" << endl;
                return 0;
            }
        }
    cout << "Source\tDestination\tDistance\n";
    for(int i = 0; i<dist.size(); i++){
        cout << "0\t" << i << "\t\t" << dist[i] << endl;
    }
    return 0;
}