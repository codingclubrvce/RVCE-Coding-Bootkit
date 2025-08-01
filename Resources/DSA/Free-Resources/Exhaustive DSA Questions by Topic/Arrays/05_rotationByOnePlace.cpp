// Rotation of an array by oneplace, towards the left.

#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of array elements" << endl;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int temp = arr[0];
    for(int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }
    cout << "Array after left shifting by one place is:" << endl;
    arr[n-1] = temp;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}