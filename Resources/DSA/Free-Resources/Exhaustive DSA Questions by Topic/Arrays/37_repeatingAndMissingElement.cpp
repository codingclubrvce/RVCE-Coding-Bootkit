/**
 * Finding the repeating element and missing element
 * array[] = {3,1,2,5,3}
 * A = 3 , B = 4 
 * Since 3 is appearing twice and 4 is missing
*/

#include<iostream>
#include<vector>
using namespace std;


/**
 * Brute Solution
 * TC : O(N^2)
 * SC : O(1)
*/
vector<int> brute(vector<int> nums){
    int n = nums.size();
    int missing = -1;
    int repeating = -1;
    for(int i = 1; i<n; i++){
        int count = 0;
        for(int j = 0; j<n; j++) {
            if(nums[j] == i){
                count ++;
            }
        }
        if(count == 2){
            repeating = i;
        }
        else if(count == 0){
            missing = i;
        }
        if(repeating != -1 && missing != -1){
            break;
        }
    }
    return {repeating, missing};
}

/**
 * Better Solution 
 * TC : O(2N)
 * SC : O(N)
*/
vector<int> better(vector<int> nums){
    int n = nums.size();
    vector<int> hash(n+1, 0);
    for(int i = 0; i < n; i++){
        hash[nums[i]]++;
    }
    int repeating = -1;
    int missing = -1;
    for(int i = 1; i <= n; i++){
        if(hash[i] == 2){
            repeating = i;
        }
        else if(hash[i] == 0){
            missing = i;
        }
        if(repeating != -1 && missing != -1){
            break;
        }
    }
    return {repeating, missing};
}

/**
 * Optimal Solution using MATHS
 * TC : O(N)
 * SC : O(1)
*/
vector<int> optimal(vector<int> nums){
    int n = nums.size();
    long long sn = n*(n+1)/2;
    long long s2n = n*(n+1)*(2*n+1)/6;
    long long s = 0, s2 = 0;
    for(int i = 0; i<n; i++){
        s = s + nums[i];
        s2 = s2 + nums[i]*nums[i];
    }
    long long val1 = s-sn; // x-y (repeating - missing)
    long long val2 = (s2-s2n)/(val1); // x+y
    long long x = (val1 + val2)/2;
    long long y = x - val1;
    return {(int)x, (int)y};
}

int main(){
    vector<int> nums = {3, 1, 2, 5, 3};
    vector<int> ans = optimal(nums);
    cout << "Repeating element = " << ans[0] << endl;
    cout << "Missing element = " << ans[1] << endl;
    return 0;
}