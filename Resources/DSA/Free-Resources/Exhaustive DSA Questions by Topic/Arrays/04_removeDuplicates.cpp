//Remove duplicate elements from an array which is sorted and print number of unqiue elements present

/*
    TC : O(N)
    SC : O(1)
*/

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
    
    int s=0;
    for(int j=1; j<n; j++){
        if(arr[j]!=arr[s]){
            arr[s+1] = arr[j];
            s++;
        }
    }
    cout << "Number of unqiue elements: " << s+1 << endl;

}