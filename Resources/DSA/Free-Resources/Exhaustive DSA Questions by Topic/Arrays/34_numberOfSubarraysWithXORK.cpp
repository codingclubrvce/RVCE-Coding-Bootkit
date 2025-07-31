#include<iostream>
#include<vector>
#include<map>
using namespace std;

/**
 * BRUTE - 3 Nested Loops
 * TC : O(N^3)
 * SC : O(1)
*/
int brute(vector<int> nums, int target){
    int c =0;
    for(int i = 0; i<nums.size(); i++){
        for(int j = i; j<nums.size(); j++){
            int XOR = 0;
            for(int k = i; k<=j; k++){
                XOR = XOR ^ nums[k];
            }
            if(XOR == target){
                c++;
            }
        }
    }
    return c;
}

/**BETTER - Eliminate use of 3rd Loop
 * TC : O(N^2)
 * SC : O(1)
*/
int better(vector<int> nums, int target){
    int c = 0;
    for(int i = 0; i<nums.size(); i++){
        int XOR = 0;
        for(int j = i; j<nums.size(); j++){
            XOR = XOR ^ nums[j];
            if(XOR == target){
                c++;
            }
        }
    }
    return c;
}

/**OPTIMAL SOLUTION
 * TC : O(NlogN) Best Case is O(N)
 * SC : O(N) at the worst case if each element is unique
*/
int optimal(vector<int> nums, int target){
    int xr = 0;
    int count = 0;
    map<int, int> mpp;
    mpp[xr]++; // {0, 1} is inserted before starting
    for(int i = 0; i<nums.size(); i++){
        xr = xr^nums[i];
        int x = xr ^ target;
        count = count + mpp[x];
        mpp[x]++;
    }
    return count;
}

int main(){
    vector<int> nums = {4, 2, 2, 6, 4};
    int target = 6;
    cout << optimal(nums, target);
    return 0;
}