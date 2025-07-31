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
    vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };
    DisjointSet ds(accounts.size());
    map<string, int> mpp;
    for(int i = 0; i<accounts.size(); i++){
        for(int j = 1; j<accounts[i].size(); j++){
            if(mpp.find(accounts[i][j]) == mpp.end()){
                mpp[accounts[i][j]] = i;
            }
            else{
                ds.unionByRank(i, mpp[accounts[i][j]]);
            }
        }
    }
    vector<vector<string>> temp(accounts.size());
    vector<vector<string>> ans;
    for(auto it:mpp){
        it.second = ds.findParent(it.second);
        temp[it.second].push_back(it.first);
    }
    for(int i = 0; i<temp.size(); i++){
        if(temp[i].size()==0){
            continue;
        }
        else{
            temp[i].insert(temp[i].begin(), accounts[i][0]);
            ans.push_back(temp[i]);
        }
    }
    for (auto acc : ans) {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}