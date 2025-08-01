//Finding second largest and second smallest elements in an array 0f elements.

#include<iostream>
#include<vector>
using namespace std;

int secondLargest(vector<int> a, int n){
    int largest = a[0];
    int second_largest = -1;
    for(int i=1; i<n; i++){
        if(largest < a[i]){
            //shifting of largest to second largest as soon as even larger element is encountered.
            second_largest = largest;
            largest = a[i];
        }
        else if(second_largest < a[i] && a[i] < largest){
            second_largest = a[i];
        }
    }
    return second_largest;
}

int secondSmallest(vector<int> a, int n){
    int smallest = a[0];
    int second_smallest = INT_MAX;
    for(int i=1; i<n; i++){
        if(smallest > a[i]){
            //shifting of smallest to second smallest as soon as even smaller element is encountered.
            second_smallest = smallest; 
            smallest = a[i];
        }
        if(a[i] != smallest && a[i] < second_smallest){
            second_smallest = a[i];
        }
    }
    return second_smallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int slargest = secondLargest(a, n);
    int ssmallest = secondSmallest(a, n);
    return {slargest, ssmallest};
}

int main(){
    int n;
    cout << "Enter number of elements in an array" << endl;
    cin >> n;
    cout << "Enter array elements" << endl;
    vector<int> arr(n);  // Corrected to initialize vector with size 'n'
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> result = getSecondOrderElements(n, arr);  // Corrected function call
    cout << "Second Largest = " << result[0] << endl;
    cout << "Second Smallest = " << result[1] << endl;
    return 0;  // Added return statement
}
