//Print name entered for N number of time using recursion

#include<iostream>
#include<string>
using namespace std;

void printName(int i, int N, string str){
    if(i > N){
        return;
    }
    cout << str << endl;
    printName(i+1, N, str);
}

int main(){
    string name;
    getline(cin, name);
    int n;
    cin >> n;
    printName(1, n, name);
}