#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
    Brute Force
    TC : O(N^2)
    SC : O(1)
*/
int brute(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        int count = 0;
        for(int j=0; j<arr.size(); j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > (arr.size()/2)){
            return arr[i];
        }
    }
    return -1;
}

/*
    Better - Hashing
    TC : O(NlogN) + O(N)
    SC : O(N)
*/
int better(vector<int> arr){
    map<int, int> mpp;
	for(int i=0; i<arr.size(); i++){
		mpp[arr[i]]++;
	}
	for(auto it : mpp){
		if(it.second > (arr.size()/2)){
			return it.first;
		}
	}
    return -1;
}

/*
    Optimal - Moore's Voting Algorithm
    TC : O(N)
    SC : O(1)
*/
int optimal(vector<int> arr){
    int count = 0;
    int el;
    for(int i=0; i<arr.size(); i++){
        if(count == 0){
            count = 1;
            el = arr[i];
        }
        else if (arr[i] == el){
            count++;
        }
        else count--;
    }
    return el;
}

int main(){
    vector<int> arr = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
    // int majEl = brute(arr);
    // int majEl = better(arr);
    int majEl = optimal(arr);
    cout << majEl << endl;
    return 0;
}