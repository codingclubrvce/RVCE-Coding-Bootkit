#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout << "Enter number of array elements" << endl;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    //BRUTE FORCE SOLUTION
    /*
        vector<int> temp;
        for(int i=0; i<n; i++){
            if(arr[i] !=0){
                temp.push_back(arr[i]);
            }
        }
        for(int i=0; i<temp.size(); i++){
            arr[i] = temp[i];
        }
        for(int i=temp.size(); i<n; i++){
            arr[i] = 0;
        }
    */

    //OPTIMAL SOLUTION
    int j=-1;
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            j=i; //find index of first zero and assign it to 'j'
            break;
        }
    }
    for(int i=j+1; i<n; i++){ //'i' is the first element after 'j'
        if(arr[i]!=0){ //since element at 'i' is not zero, we swap it with 'j' which is a zero, 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++; 
        }
    }
    
    cout << "Modified Array :";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}