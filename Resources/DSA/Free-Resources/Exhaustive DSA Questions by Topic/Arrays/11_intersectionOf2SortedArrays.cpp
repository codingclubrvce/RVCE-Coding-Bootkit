/*
    Intersection of 2 Sorted Arrays
*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

// Two Pointer Approach
vector<int> doIntersection(vector<int> a, vector<int> b, int n1, int n2){
    int i=0; // First Array Pointer
    int j=0; // Second Array Pointer
    vector<int> result;
    while(i<n1 && j<n2){ //Until both Pointers are within limits
        if(a[i] < b[j]){ //If first array elem is smaller, shift i
            i++;
        }
        else if(b[j] < a[i]){ //If second array elem is smaller, shift j
            j++;
        }
        else{
            result.push_back(a[i]); // If both equal, push elem and shift both i and j
            i++;
            j++;
        }
    }
    return result;
}

int main(){
    vector<int> a = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> b = {2, 3, 3, 5, 6 ,6, 7};
    int n1 = a.size();
    int n2 = b.size();
    vector<int> ans = doIntersection(a, b, n1, n2);
    
    /*
        int visited[n2] = {0};
        // BRUTE FORCE Solution

            TC : O(n1 x n2)
            SC : O(N2)

        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(a[i] == b[j] && visited[j] == 0){
                    ans.push_back(a[i]);
                    visited[j] = 1;
                    break;
                }   
                if(b[j] > a[i]){
                    break;
                }
            }
        }
    */

    for(auto it : ans){
        cout << it << " ";
    }
}