//Largest elements in an array (unsorted).

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
    int max = 0;
    for(int i=1; i<n; i++){
        if(arr[i] >= arr[max]){
            max = i;
        }
    }
    cout << "Largest element is " << arr[max] << endl;
}