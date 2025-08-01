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
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };
    DisjointSet ds(n*m);
    int vis[n][m];
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    vector<int> ans;
    for(auto it:operators){
        int r = it[0];
        int c = it[1];
        if(vis[r][c]){
            ans.push_back(cnt);
            continue;
        }
        vis[r][c] = 1;
        cnt++;
        // r-1, c
        // r, c+1
        // r+1, c
        // r, c-1
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int i = 0; i<4; i++){
            int xi = r+dx[i];
            int yi = c+dy[i];
            if(xi>=0 && yi>=0 && xi<n && yi<m && vis[xi][yi] == 1){
                int a = r*m+c;
                int b = xi*m + yi;
                if(ds.findParent(a) != ds.findParent(b)){
                    cnt--;
                    ds.unionByRank(a, b);
                }
            }
        }
        ans.push_back(cnt);
    }
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}