/*
    Maximum consecutive ones in an array of 0's and 1's
    arr[] = [1, 1, 0, 1, 1, 1, 0, 0, 1, 1]
    ans = 3

    TC : O(N)
    SC : O(1)
*/

#include<vector>
#include<iostream>
using namespace std;

int main(){
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 0, 1, 1};
    int n = arr.size();
    int count = 0;
    int max = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            count++;
            if(count > max){
                max = count;
            }
        }
        else
            count = 0;
    }
    cout << max << endl;
}