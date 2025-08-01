/**
 * Element occuring more than n/3 times in an array
*/

// Brute - same as n/2 times, just make array to add elements and finish if 2 elements added
// Better (Hashing) - same as n/2 times, just make array to add elements and finish if 2 elements added

#include<iostream>
#include<vector>
using namespace std;

/**
 * Moore's Voting Algorithm - Modified Version
*/
vector<int> optimal(vector<int> nums){
    int c1 = 0; 
    int c2 = 0;
    int e1 = INT_MIN, e2 = INT_MIN;
    for(int i = 0 ; i<nums.size(); i++){
        if(c1 == 0 && nums[i] != e2){
            c1 = 1;
            e1 = nums[i];
        }
        else if(c2 == 0 && nums[i] != e1){
            c2 = 1;
            e2 = nums[i];
        }
        else if(nums[i] == e1){
            c1++;
        }
        else if(nums[i] == e2){
            c2++;
        }
        else{
            c1--;
            c2--;
        }
    }
    //Manual checking of frequency
    c1 = 0;
    c2 = 0;
    for(int i = 0 ; i<nums.size(); i++){
        if(nums[i] == e1){
            c1++;
        }
        if(nums[i] == e2){
            c2++;
        }
    }
    // return only if greater than n/3
    vector<int> result;
    int mini = (int)nums.size()/3 + 1;
    if(c1 >= mini){
        result.push_back(e1);
    }
    if(c2 >= mini){
        result.push_back(e2);
    }
    return result;
}
int main(){
    vector<int> nums = {4};
    vector<int> ans = optimal(nums);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}