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

        void unionByRank(int u, int v){
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

int main(){
    vector<vector<int>> stones = {{0, 0}, {0, 2}, {1, 3}, {3, 1}, {3, 2}, {4, 3}};
    int n = 0;
    int m = 0;
    for(int i = 0; i<stones.size(); i++){
        n = max(n, stones[i][0]);
        m = max(m, stones[i][1]);
    }
    n++;
    m++;
    DisjointSet ds(n+m+1);
    set<int> st;
    for(int i = 0; i<stones.size(); i++){
        int r = stones[i][0];
        int c = stones[i][1] + n;
        ds.unionByRank(r, c);
        st.insert(r);
    }
    int c = 0;
    for(auto it:st){
        if(it == ds.findParent(it)) c++;
    }
    cout << "Removed: " << stones.size() - c << endl;
    return 0;
}