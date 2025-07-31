/*
    Union of 2 Sorted Arrays using 2 pointer approach

    Note on Time and Space Complexity
        TC : O(n1+n2)    
        SC : O(n1+n2)
*/ 


#include<bits/stdc++.h>
using namespace std;

// Two - Pointer Approach
vector<int> doUnion(vector<int> v1, vector<int> v2){
    int n1 = v1.size(); //size of first vector
    int n2 = v2.size(); //size of second vector
    int i = 0; //pointer for first vector
    int j = 0; //pointer for second vector
    vector<int> ans;
    while(i<n1 && j<n2){ //until both pointers are within range
        if(v1[i] <=v2[j]){ //select smaller element
            if(ans.size() == 0 || ans.back() != v1[i]){ //check if the current element is different from the previous element.
                ans.push_back(v1[i]);
            }
            i++;
        }
        else{
            if(ans.size() == 0 || ans.back() != v2[j]){
                ans.push_back(v2[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(ans.size() == 0 || ans.back() != v1[i]){
                ans.push_back(v1[i]);
            }
            i++;
    }
    while(j<n2){
        if(ans.size() == 0 || ans.back() != v2[j]){
                ans.push_back(v2[j]);
            }
            j++;
    }
    return ans;
}

int main(){
    vector<int> a = {1, 1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 4, 5, 6};
    vector<int> result = doUnion(a, b);
    for(auto it : result){
        cout << it << " ";
    }
    return 0;
}