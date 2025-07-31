#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }

        void unionByRank(int u, int v, int w, vector<pair<int, int>>& mst, int &sum){
            int ulu = findParent(u);
            int ulv = findParent(v);
            if(ulu == ulv) return;
            if(rank[ulu] < rank[ulv]){
                parent[ulu] = ulv;
            }
            else if(rank[ulv] < rank[ulu]){
                parent[ulv] = ulu;
            }
            else{
                parent[ulv] = ulu;
                rank[ulv]++;
            }
            mst.push_back({u, v});
            sum+=w;
        }

        void unionBySize(int u, int v){
            int ulu = findParent(u);
            int ulv = findParent(v);
            if(ulu == ulv) return;
            if(size[ulu] < size[ulv]){
                parent[ulu] = ulv;
                size[ulv] = size[ulv]+size[ulu];
            }
            else{
                parent[ulv] = ulu;
                size[ulu] = size[ulu]+size[ulv];
            }
        }
};

bool comp(vector<int> a, vector<int> b){
    return a[0]<b[0];
}

int main(){
    vector<vector<int>> edges = {{2, 1, 2}, {3, 2, 3}, {3, 2, 4}, 
                                {4, 1, 5}, {1, 1, 4}, {5, 3, 4}, 
                                {7, 2, 6}, {8, 3, 6}, {9, 4, 5}};
    sort(edges.begin(), edges.end(), comp);
    DisjointSet ds(6);
    int sum = 0;
    vector<pair<int, int>> mst;
    for(int i = 0; i<edges.size(); i++){
        ds.unionByRank(edges[i][1], edges[i][2], edges[i][0], mst, sum);
    }
    cout << "Sum of MST Edges: " << sum << endl;
    cout << "MST: " << endl;
    for(int i = 0; i<mst.size(); i++){
        cout << "(" << mst[i].first << ", " << mst[i].second << ")" << endl;
    }
    return 0;
}