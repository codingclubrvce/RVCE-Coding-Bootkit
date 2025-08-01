#include<iostream>
#include<vector>
using namespace std;

bool checkSorted(vector<int> arr, int n){
    for(int i=0; i<n; i++){
        if(arr[i] >= arr[i-1]){

        }
        else return false;
    }
    return true;
}

int main(){
    int n;
    cout << "Enter number of array elements" << endl;
    cin >> n;
    vector<int> arr = {0};
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool check = checkSorted(arr, n);
    if(check==true){
        cout << "Sorted Array" << endl;
    }
    else if(check==false){
        cout << "UnSorted Array" << endl;
    }
}