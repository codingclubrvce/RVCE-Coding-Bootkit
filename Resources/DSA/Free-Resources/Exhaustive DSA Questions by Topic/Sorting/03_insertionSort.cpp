//Insertion Sort - start picking elements from the left and place them in correct order by comparing whether they are larger than the immediately preceding element.
/*
    Note on Time Complexity:-
    TC : O(N^2)
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

    //INSERTION SORT
    for(int i=1; i<n; i++){
        int j=i; //to start inserting elements from the left side. The value of i increases in this loop indicating that the array elements have already been put into the correct places.
        while(j>0 && arr[j-1]>arr[j]){ //check if immediately preceding element is greater
            //swapping elements
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

    //Sorted Array
    cout << "Sorted Array :-" << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}