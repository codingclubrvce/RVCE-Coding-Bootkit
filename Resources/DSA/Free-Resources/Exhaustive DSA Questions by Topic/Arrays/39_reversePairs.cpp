/**
 * Reverse Pairs 
 * a[i] > 2*a[j] and i<j
*/

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high){
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr
    //storing elements in the temporary array in a sorted manner//
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right++;
        }
    }
    // if elements on the left half are still left //
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }
    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }
    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

int countPairs(vector<int>& nums, int low, int mid, int high){
    int count = 0;
    int right = mid+1;
    for(int i = low; i <= mid; i++){
        while((right <= high) && (nums[i] > 2*nums[right])){
            right++;
        }
        count = count + right - (mid + 1);
    }
    return count;
}

int mergeSort(vector<int>& nums, int low, int high){
    int count = 0;
    if(low>=high){
        return count;
    }
    int mid = (low+high)/2;
    count = count + mergeSort(nums, low, mid);
    count = count + mergeSort(nums, mid+1, high);
    count = count + countPairs(nums, low, mid, high);
    merge(nums, low, mid, high);
    return count;
}

int optimal(vector<int>& nums){
    return mergeSort(nums, 0, nums.size()-1);
}

int main(){
    vector<int> nums = {1,3,2,3,1};
    int cnt = optimal(nums);
    cout << "The number of reverse pair is: " << cnt << endl;
    return 0;
}