// arr[] = [102, 4, 100, 1, 101, 3, 2, 1, 1]
// ans = 4 because [1, 2, 3, 4] is the longest consecutive sequence and not [100, 101, 102]

#include<set>
#include<unordered_set>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool linearSearch(vector<int> arr, int elem){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == elem){
            return true;
        }
    }
    return false;
}

int brute(vector<int> nums){
    // TC : O(N^2)
    int longest = 1;
    for(int i = 0; i<nums.size(); i++){
        int x = nums[i];
        int count = 1;
        while(linearSearch(nums, x+1) == true){
            x++;
            count++;
        }
        longest = max(longest, count);
    }
    return longest;
}

int better(vector<int> nums){
    // TC : O(N+NlogN)
    sort(nums.begin(), nums.end());
    int lastSmaller = INT_MIN;
    int count = 0;
    int longest = 1;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i]-1 == lastSmaller){
            count++;
            lastSmaller = nums[i];
        }
        else if (nums[i] != lastSmaller){
            count = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, count);
    }
    return longest;
}

int optimal(vector<int> nums){
    // TC : O(3N)
    // SC : O(N)
    if(nums.size() == 0){
        return 0;
    }
    int longest = 1;
    unordered_set<int> st;
    for(int i = 0; i<nums.size(); i++){
        st.insert(nums[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int count = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                count++;
                x++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main(){
    vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    int ans = optimal(nums);
    cout << ans << endl;
}