/**
 * The two given arrays are in sorted fashion
 * Example 1:
 * Input:
 * n = 4, arr1[] = [1 4 8 10]
 * m = 5, arr2[] = [2 3 9]
 * Output:
 * arr1[] = [1 2 3 4]
 * arr2[] = [8 9 10]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * Brute Force
 * TC : O(N+M)
 * SC : O(N+M)
*/
void brute(vector<int>& arr1, vector<int>& arr2){
    vector<int> arr3;
    int left = 0;
    int right = 0;
    int m = arr1.size();
    int n = arr2.size();
    while(left < m && right < n){
        if(arr1[left] < arr2[right]){
            arr3.push_back(arr1[left]);
            left++;
        }
        else if(arr2[right] < arr1[left]){
            arr3.push_back(arr2[right]);
            right++;
        }
        else if(arr1[left] == arr2[right]){
            arr3.push_back(arr2[right]);
            right++;
        }
    }
    while(left < m){
        arr3.push_back(arr1[left]);
        left++;
    }
    while(right < n){
        arr3.push_back(arr2[right]);
        right++;
    }
    for(int i = 0; i<m; i++){
        arr1[i] = arr3[i];
        arr2[i] = arr3[i+m];
    }
}

/**
 * Better approach - swapping all the greater elements from first array to second array and then individually sort them
 * TC : O(min(N, M)) + O(NlogN) + O(MlogM)
 * SC : O(1)
*/
void better(vector<int>& arr1, vector<int>& arr2){
    int m = arr1.size();
    int n = arr2.size();
    int left = m-1;
    int right = 0;
    while(left >=0 && right < n){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

void optimal(vector<int>& arr1, vector<int>& arr2){
    int m = arr1.size();
    int n = arr2.size();
    int len = n+m;
    int gap = len/2 + len%2;
    while(gap>0){
        int left = 0; 
        int right = left + gap;
        while(right < len){
            if(left < m && right >= m){ //lies in arr1 and arr2
                if(arr1[left] > arr2[right-m]){
                    swap(arr1[left], arr2[right-m]);
                }
            }
            else if(left >= m) { //lies in arr2, arr2
                if(arr2[left-m] > arr2[right-m]){
                    swap(arr2[left-m], arr2[right-m]);
                }
            }
            else{ //lies in arr1, arr1
                if(arr1[left] > arr1[right]){
                    swap(arr1[left], arr1[right]);
                }
            }
            left++;
            right++;
        }
        if(gap == 1){
            break;
        }
        gap = gap/2 + gap%2;
    }
}

int main(){
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};
    optimal(arr1, arr2);
    for(int i = 0; i<arr1.size(); i++) cout << arr1[i] << " ";
    cout << endl;
    for(int i = 0; i<arr2.size(); i++) cout << arr2[i] << " ";
    return 0;
}