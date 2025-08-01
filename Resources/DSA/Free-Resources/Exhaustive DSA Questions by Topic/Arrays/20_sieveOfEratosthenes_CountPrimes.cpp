#include<iostream>
using namespace std;

int N = 1000000;
bool isPrime [1000001];
void createSieve(){
    for(int i=2; i<=N; i++){
        isPrime[i] = true;
    }
    for(int i = 2 ; i*i <= N; i++){
        if(isPrime[i] == true){
            for(int j = i*i; j <= N; j= j+i){
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    createSieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(isPrime[n] == true){
            cout << "True" << endl;
        }
        else{
            cout << "False" << endl;
        }
    }
}

/*
Intuition

An array isPrime is created to store true and false values whether a number is prime or not. We use the Sieve Of Eratosthenes approach for this problem, where we mark all multiples of prime numbers as false.

Approach

The size of isPrime array is n and initially all the values are set to be true. We start the outer loop from 2, and since 2 is marked as true the if(isPrime[i] == true) is satisfied and we move to the inner loop where j starts from 2x2=4 and post this it keeps converting multiples of 2 as false; We increment value of j by j = i+j because we want to jump over to 4, 6, 8 and not on 3, 5, 7 etc. The reason for taking initial value j = i*i is that we are willing to start from 9 when it comes to 3 since 6 has already been marked. Similarly while outer loop is 5, we will start from 25, because 10, 15 and 20 are already marked false.

Complexity
Time complexity:
O(Nlog(logN)) viz equivalent to O(N)

Space complexity:
O(N)
*/