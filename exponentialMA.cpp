// exponential moving average
// S_t = a * Y_t + (1-a) * S_t-1

#include<vector>
#include<iostream>
using namespace std;

class Solution{
  public:
    Solution(): n(5) {}
    void expMA(const vector<double> &data) {
      if (data.size() == 0) return;
      alpha = 1.0/data.size();
      movingAverage.push_back(data[0]);
      for(vector<double>::const_iterator a = data.begin() + 1; a != data.end(); a++) {
        movingAverage.push_back(alpha * (*a) + (1 - alpha) * movingAverage.back());
      }
      return;
    }
    const vector<double>& getMA() {
      return movingAverage;
    }
  private:
    vector<double> movingAverage;
    size_t n;
    double alpha;
};


int main() {
  Solution solution;
  vector<double> data{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  solution.expMA(data);
  vector<double> myMA = solution.getMA();
  for(vector<double>::iterator a = myMA.begin(); a != myMA.end(); a++) {
    cout << *a << endl;
  }
}
