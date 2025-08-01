#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
/*
Category 1 - Equal number of positives and negatives
*/
int main(){
    vector<int> arr = {1, 2, -3, -4, 3, -8};
    /*
    Brute force solution
        TC : O(3N/2)
        SC : O(N)
    */
    int n = arr.size();
    vector<int> pos, neg;
    for(int i = 0 ; i<n; i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else 
            neg.push_back(arr[i]);
    }
    for(int i = 0; i<n/2; i++){
        arr[i*2] = pos[i];
        arr[i*2+1] = neg[i];
    }

    /*
    Optimal Solution
        TC : O(N)
        SC : O(N)
    */
    vector<int> ans(arr.size());
    int pos = 0;
    int neg = 1;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] > 0){
            ans[pos] = arr[i];
            pos=pos+2;
        }
        else{
            ans[neg] = arr[i];
            neg=neg+2;
        }
    }

    for(int i = 0; i<arr.size(); i++){
        cout << ans[i] << ", ";
    }
}

/*
    Category 2 - pos != neg
        TC : O(2N)
        SC : O(N)
*/

int cat2(){
    arr2 = {1, 2, 3, -1, -2, 5, 6}
    int n = arr2.size();
    vector<int> pos, neg;
    for(int i = 0 ; i<n; i++){
        if(arr[i] > 0){
            pos.push_back(arr2[i]);
        }
        else 
            neg.push_back(arr2[i]);
    }
    if(pos.size() > neg.size()){
        for(int i = 0; i<neg.size(); i++){
           arr2[2*i] = pos[i];
           arr2[2*i + 1] = neg[i];
        }
        int ind = 2*neg.size();
        for(int i = neg.size(); i<pos.size(); i++){
            arr[ind] = pos[i];
            ind++;
        }
    }
    else{
        for(int i = 0; i<pos.size(); i++){
           arr2[2*i] = pos[i];
           arr2[2*i + 1] = neg[i];
        }
        int ind = 2*pos.size();
        for(int i = pos.size(); i<neg.size(); i++){
            arr[ind] = neg[i];
            ind++;
        }
    }
}