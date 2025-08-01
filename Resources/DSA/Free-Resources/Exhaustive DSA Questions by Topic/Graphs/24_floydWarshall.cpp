#include <bits/stdc++.h>
using namespace std;

int main(){
    int V = 4;

    vector<vector<int>> a(V, vector<int>(V, -1));
	a[0][1] = 2;
	a[1][0] = 1;
	a[1][2] = 3;
	a[3][0] = 3;
	a[3][1] = 5;
	a[3][2] = 4;
    
    for(int i = 0; i<a.size(); i++){
        for(int j = 0; j<a[0].size(); j++){
            if(i==j) a[i][j] = 0;
            else if(a[i][j] == -1){
                a[i][j] = 1e9;
            }
        }
    }
    cout << "Before Processing:" << endl;
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            if(a[i][j] == 1e9){
                cout << "INF ";
            }
            else{
                cout << a[i][j] << "   ";
            }
        }
        cout << endl;
    }

    for(int via = 0; via<V; via++){
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(a[i][via] == 1e9 || a[via][j] == 1e9){
                    continue;
                }
                a[i][j] = min(a[i][j], a[i][via]+a[via][j]);
            }
        }
    }
    cout << "After Processing:" << endl;
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            if(a[i][j] == 1e9){
                cout << "INF ";
            }
            else{
                cout << a[i][j] << "   ";
            }
        }
        cout << endl;
    }
    return 0;
}