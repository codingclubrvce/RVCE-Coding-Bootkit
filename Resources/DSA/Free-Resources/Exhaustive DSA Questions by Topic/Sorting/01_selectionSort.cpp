//Sorting an Array using Selection Sort
/*
    Note on Time Complexity:-
    - O(N^2) in all cases: Best, Average, Worst
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of array elements :-" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array elements :-" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //SELECTION SORT
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }   

    //Sorted Array
    cout << "Sorted Array :-" << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}