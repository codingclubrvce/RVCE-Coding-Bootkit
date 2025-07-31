//Bubble Sort - send maximum element to the end of a matrix by adjacent swapping
/*
    Note on Time Complexity:-
    - Worst and Average = O(N^2)
    - Best = O(N) because we stop the loop as soon as we find that none of the adjacent elements were swapped.
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

    //BUBBLE SORT

    // for(int i=n-1; i>=1; i--){
    //     int didswap = 0; //to reduce time complexity
    //     for(int j=0; j<i;j++){
    //         if(arr[j] > arr[j+1]){
    //             int temp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = temp;
    //             didswap = 1;
    //         }
    //     }
    //     if(didswap==0){
    //         break;
    //     }
    // }

    for(int i=0; i<n; i++){
        int didswap = 0; //to reduce time complexity
        for(int j=0; j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didswap = 1;
            }
        }
        if(didswap==0){
            break;
        }
    }

    //Sorted Array
    cout << "Sorted Array :-" << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}