#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>& a){
    queue<pair<int, int>> q;
    int total = 0;
    for(int i = 0; i<a.size(); i++){
        for(int j = 0; j<a[0].size(); j++){
            if(a[i][j]!=0) total++;
            if(a[i][j]==2){
                q.push({i, j});
            }
        }
    }
    int rotten = 0;
    int ans = 0;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    while(!q.empty()){
        rotten = rotten + q.size();
        int s = q.size();
        for(int i = 0; i<s; i++){
            pair<int, int> p = q.front();
            q.pop();
            for(int k = 0; k<4; k++){
                int nr = p.first + dx[k];
                int nc = p.second + dy[k];
                if(nr>=0 && nc>=0 && nr<a.size() && nc<a[0].size() && a[nr][nc]==1){
                    a[nr][nc]=2;
                    q.push({nr, nc});
                }
            }
        }
        if(!q.empty()) ans++;
    }
    if(total == rotten) return ans;
    return -1;
}

int main(){
    vector<vector<int>> a = {
        {2, 1, 1},
        {1, 0, 1},
        {1, 1, 2}
    };
    int ans = bfs(a);
    if(ans == -1) cout << "Not possible to rot all oranges!" << endl;
    else cout << ans << endl;
    return 0;
}