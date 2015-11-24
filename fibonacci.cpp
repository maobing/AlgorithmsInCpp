#include<iostream>
// Note: when n is large, the int will overflow.
using namespace std;

class fibonacci{
public:
  fibonacci() {};
  ~fibonacci() {};
  int recursiveFibonacci(int n);
  int iterativeFibonacci(int n);
};

int fibonacci::recursiveFibonacci(int n) {
  if(n < 0) return -1;
  if(n == 0 || n == 1) return n;
  return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
}

int fibonacci::iterativeFibonacci(int n) {
  if(n < 0) return -1;
  if(n == 0 || n == 1) return n;

  int f_prev1 = 0, f_prev2 = 1;
  int f_n = 0;
  for(int i = 2; i <= n; i ++) {
    f_n = f_prev1 + f_prev2;
    f_prev1 = f_prev2;
    f_prev2 = f_n;
  }
  return f_n;
}

int main() {
  cout << "Enter the rank of number you want to get" << endl;
  int n;
  cin >> n;
  fibonacci myFibonacci;
  cout << "iterative: The number is " << myFibonacci.iterativeFibonacci(n) << endl;
  cout << "recursive: The number is " << myFibonacci.recursiveFibonacci(n) << endl;
}

  
