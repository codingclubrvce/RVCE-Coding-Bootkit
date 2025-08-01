#include <bits/stdc++.h>
using namespace std;

int main(){
    
    //* 1. ADJACENCY MATRIX
    //! SC - O(N^2)
    //! TC - O(N)

    // cout << "Adjacency Matrix representation: " << endl;
    int n, m;
    // cin >> n >> m;
    // vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    // for(int i = 0; i<m; i++){
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }
    // for(int i = 0; i<n+1; i++){
    //     for(int j = 0; j<n+1; j++){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //* 2. ADJACENCY LIST
    //! SC - O(2M) - un directed
    //! SC - o(M) - directed
    //! TC - O(N)
    cout << "Adjacency List represenation: " << endl;
    cin >> n >> m;
    vector<vector<int>> a(n+1);
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 0; i<n+1; i++){
        cout << i << " : ";
        for(int j = 0; j<a[i].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

