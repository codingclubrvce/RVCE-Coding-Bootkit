#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> adj, vector<int>& vis, stack<int>& st){
    vis[i] = 1;
    for(auto it:adj[i]){
        if(!vis[it]) dfs(it, adj, vis, st);
    }
    st.push(i);
}


int main(){
    vector<string> a = {"baa", "abcd", "abca", "cab", "cad"};
    int k = 4;
    int n = a.size();
    vector<vector<int>> adj(k);
    for(int i = 0; i<n-1; i++){
        string x = a[i];
        string y = a[i+1];
        cout << "Checking " << x << " and " << y << endl;
        int len = min(x.length(), y.length());
        for(int j = 0; j<len; j++){
            if(x[j]!=y[j]){
                cout << "Mismatch at " << x[j] << " and " << y[j] << endl;
                adj[x[j]-'a'].push_back(y[j]-'a');
                break;
            }
        }
    }
    for(int i = 0; i<adj.size(); i++){
        cout << char(i+'a') << ": ";
        for(int j = 0; j<adj[i].size(); j++){
            cout << char(adj[i][j]+'a') << " ";
        }
        cout << endl;
    }
    stack<int> st;
    vector<int> vis(adj.size(), 0);
    for(int i = 0; i<adj.size(); i++){
        if(!vis[i]) dfs(i, adj, vis, st);
    }
    cout << "Topological Order: ";
    while(!st.empty()){
        cout << char(st.top()+'a') << " ";
        st.pop();
    }
    return 0;
}