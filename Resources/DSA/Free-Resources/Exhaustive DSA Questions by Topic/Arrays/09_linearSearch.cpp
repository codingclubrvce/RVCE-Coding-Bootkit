#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of array elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements:" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int num;
    cout << "Enter the number to be searched:";
    cin >> num;
    int flag = -1;
    for(int i=0; i<n; i++){
        if(num == arr[i]){
            flag = i;
            break;
        }
    }
    if(flag != -1){
        cout << "Search successful at index " << flag << endl;
    }
    else cout << "Search unsuccessful" << endl;
}