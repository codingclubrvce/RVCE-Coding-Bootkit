#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


/**
 * Brute Force
 * TC : O(NlogN) + O(2N)
 * SC : O(N)
*/
vector<vector<int>> brute(vector<vector<int>> &intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for(int i = 0; i < intervals.size() ; i++){
        int start = intervals[i][0];
        int end = intervals[i][1];
        if(!ans.empty() && end <= ans.back()[1])
            continue;
        for(int j = i+1 ; j<intervals.size() ; j++){
            if(intervals[j][0] <=end){
                end = max(intervals[j][1], end);
            }
            else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

/**
 * Optimal
 * TC : O(NlogN) + O(N)
 * SC : O(N)
*/
vector<vector<int>> optimal(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for(int i = 0; i < intervals.size(); i++){
        if(ans.empty() || intervals[i][0] > ans.back()[1]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> intervals={{1,3},{1,4},{2,6},{8,10}, {8, 9},{15,18}, {16,17}};
    vector<vector<int>> result = optimal(intervals);
    cout << "The merged intervals are: " << "\n";
    for (auto it : result) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}