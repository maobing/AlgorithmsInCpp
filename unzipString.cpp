#include<vector>
#include<string>
#include<cctype>
#include<iostream>
#include<sstream>

using namespace std;

// A1D2b3K2da...==> ADbbKKKdda..
// assume the number of letters can only be 1-9
class Solution {
  public:
    Solution(string zippedString_): zippedString(zippedString_), 
       unzippedString(string()) {}

    void unzipString() {
      if(zippedString.size() == 0) return;

      int num = 1;
      for(int i = 0; i < zippedString.size(); i++) {
        if(isdigit(zippedString[i])) {
          num = zippedString[i] - '0';
        } else {
          unzippedString += string(num, zippedString[i]);
          num = 1;
        }
      }
    }

    const string& getUnzippedString() { return unzippedString; }

    ~Solution() {}
  private:
    string zippedString;
    string unzippedString;
};

int main() {
  string zippedString;
  cout << "Input your zipped string: " << endl;
  getline(cin, zippedString);
  Solution solution(zippedString);
  solution.unzipString();
  cout << "The unzipped string is: " << solution.getUnzippedString() << endl;
}

