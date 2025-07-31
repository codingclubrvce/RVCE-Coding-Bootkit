//Palindrome String

#include<iostream>
#include<string>
using namespace std;

/*The right half and left half must be same for palindrome, so as soon as we find that an element is not same to the corresponding other half, we return false and if we never return false, and we reach the midpoint, we return true.*/

bool checkPalindrome(string str, int i){
    int n=str.length();
    if(i>=n/2){
        return true; //end case
    }
    if(str[i] != str[n-i-1]){
        return false;
    }
    else return (str, i+1);
}

int main(){
    string str;
    cin >> str;
    if (checkPalindrome(str, 0)){
        cout << "Palindrome String" << endl;
    }
    else
        cout << "Not Palindrome String" << endl;
    return 0;
}