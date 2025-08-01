// Rotation of an array by D places, towards the left.

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void leftRotate(int arr[], int n, int d){
    reverse(arr, arr+d); //Reverse first half
    reverse(arr+d, arr+n); //Reverse second half
    reverse(arr, arr+n); //Reverse full array
}

int main(){
    int n;
    cout << "Enter number of array elements" << endl;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int d;
    cout << "Enter the number of places the array has to be shifted.";
    cin >> d;
    d = d%n;
    /*

    BRUTE FORCE
        TC : O(N+d)
        SC : O(d)

    vector<int> temp;
    for(int i=0; i<d; i++){
        temp.push_back(arr[i]);
    }
    for(int i=d; i<n; i++){
        arr[i-d] = arr[i];
    }
    for(int i=n-d; i<n; i++){
        arr[i] = temp[i-(n-d)];
    }
    */

    /*
    OPTIMAL
        TC : O(2N)
        SC : O(1)
    */

    leftRotate(arr, n, d);

    cout << "Array after left shifting by one place is:" << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}