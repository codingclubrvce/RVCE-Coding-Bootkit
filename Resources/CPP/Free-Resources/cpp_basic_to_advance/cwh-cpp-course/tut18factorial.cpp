#include <iostream>
using namespace std;

// factorial of a number using recursion

int factorial(int n)
{
  int ans = n;
  if (n <= 1)
  {
    return 1;
  }
  ans = n * factorial(n - 1);

  return ans;
}

int main()
{

  cout << "Enter a number" << endl;
  int n;
  cin >> n;

  cout << "Factorial of " << n << " is " << factorial(n);

  return 0;
}