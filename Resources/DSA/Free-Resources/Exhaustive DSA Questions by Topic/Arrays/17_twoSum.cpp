#include<vector>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;

/*
    Brute Force
    TC : O(N^2)
    SC : O(1)
*/
void brute(vector<int> arr, int target){
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i] + arr[j] == target){
                cout << i << ", " << j << endl;
            }
        }
    }
}

/*
    Better - Hashing
    TC : O(NlogN)
    SC : O(N)
*/
void better(vector<int> arr, int target){
    map<int, int> mpp;
    for(int i=0; i<arr.size(); i++){
        int num = arr[i];
        int more = target - num;
        if(mpp.find(more) != mpp.end()){
            cout << mpp[more] << ", " << i << endl;
        }
        mpp[num] = i;
    }
}

/*
    Optimal - 2 Pointer Greedy Approach
    TC : O(N) + O(NlogN)
    SC : O(1)
*/
void optimal(vector<int> arr, int target){
    sort(arr.begin(), arr.end());
    int left = 0;
    bool flag = false;
    int right = arr.size() - 1;
    while(left < right){
        if(arr[left] + arr[right] == target){
            cout << "YES";
            flag = true;
            break;
        }
        else if((arr[left] + arr[right]) < target){
            left++;
        }
        else if((arr[left] + arr[right]) > target){
            right--;
        }
    }
    if(flag == false){
        cout << "NO";
    }
}

int main(){
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    // brute(arr, target);
    // better(arr, target);
    optimal(arr, target);
    return 0;
}