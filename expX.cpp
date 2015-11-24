#include<vector>
#include<iostream>
#include<cmath>
#include<limits>
#include<string>

using namespace std;

class expX {
public:
  expX() {};
  ~expX() {};

  double exp(double x);
private:
  double power(double base, int n);
  vector<double> cache; // for memorization to decrease time complexity of recursive calls
};

double expX::exp(double x) {

  double modified_x = x;
  int n = 1;

  if(log2(x) > 1) {
    n = pow(2, floor(log2(x)));
    modified_x = x/n;
  }

  if(x < 0) return 1/exp(-modified_x);

  double result = 1.0;
  double taylorTerm = modified_x;
  double denominator = 1.0;

  while(taylorTerm > numeric_limits<double>::min()) {
    result += taylorTerm;
    denominator++;
    taylorTerm *= modified_x/denominator;
  }
  
  return power(result, n);
}

//------------------------------------------------
// this recursive function is too slow
// use memorization to cache intermediate results
// to achieve higher efficiency
//------------------------------------------------
double expX::power(double base, int n) {
  // @NOTE: for memorization to decrease time complexity of recursive calls
  // Improved efficiency very much
  // Very good example of static variable
  static vector<double> cache(n, -1); 
  if(n == 1) return base;
  else if(cache[n] > 0) return cache[n];
  else {
    if(n % 2 == 0) {
      double res = power(base, n/2) * power(base, n/2);
      cache[n] = res;
      return res;
    } else {
      double res = base * power(base, (n-1)/2) * power(base, (n-1)/2);
      cache[n] = res;
      return res;
    }
  }
}

int main() {
  expX myexp;
  cout << "Input your power: " << endl;
  string power;
  getline(cin, power);
  cout << "e^" << power << " is " << myexp.exp(stod(power)) << endl;
  return 1;
}
