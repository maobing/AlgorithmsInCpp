#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int binarysearch(const vector<int> & s, int target) {
  int low = 0, high = s.size() - 1;
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(target > s[mid]) low = mid + 1;
    else if(target < s[mid]) high = mid - 1;
    else return mid;
  }
  return -1;
}

int binarysearchRecur(const vector<int> & s, int low, int high, int target) {
  if(low < high) {
    int mid = low + (high - low)/2;
    if(target > s[mid]) binarysearchRecur(s, mid+1, high, target);
    else if (target < s[mid]) binarysearchRecur(s, low, mid-1, target);
    else return mid;
  }
  return -1;
}

int binarysearchLower(const vector<int> & s, int target) {
  int low = 0, high = s.size() - 1;
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(target <= s[mid]) high = mid - 1;
    else low = mid + 1;
  }
  if(s[low] == target) return low;
  else return -1;
}


int binarysearchLowerInsert(const vector<int> & s, int target) {
  int low = 0, high = s.size() - 1;
  if(high < 0) return -1;
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(target <= s[mid]) high = mid - 1;
    else low = mid + 1;
  }
  return low;
}

int binarysearchUpperInsert(const vector<int> & s, int target) {
  int low = 0, high = s.size() - 1;
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(target < s[mid]) high = mid - 1;
    else low = mid + 1;
  }
  return low;
}

int binarysearchUpper(const vector<int> & s, int target) {
  int low = 0, high = s.size() - 1;
  if(high < 0) return -1;
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(target < s[mid]) high = mid - 1;
    else low = mid + 1;
  }
  if(s[low-1] == target) return low-1;
  else return -1;
}


int main() {
  cout << "Enter your vector delimited by space: " << endl;
  vector<int> s;

  int tmp;
  string line;
  getline(cin, line);
  istringstream record(line);
  while(record >> tmp) {
    s.push_back(tmp);
  }
  int i = 0;
//  for(i = 0; (int) i < s.size(); ++i) {
//    cout << "s[" << i << "] is " << s[i] << endl;
//  }

  int target;
  // cout << "Enter your target: " << endl;
  getline(cin, line);
  istringstream record2(line);
  record2 >> target;
  cout << "target is " << target << endl;
  cout << "Binary Search result (0-based) :" 
    << binarysearch(s, target) << endl;
  
  cout << "Binary Search result Lower Insert (0-based) :" 
    << binarysearchLowerInsert(s, target) << endl;
  cout << "Binary Search result Lower (0-based) :" 
    << binarysearchLower(s, target) << endl;


  cout << "Binary Search result Upper Insert(0-based) :" 
    << binarysearchUpperInsert(s, target) << endl;
  cout << "Binary Search result Upper (0-based) :" 
    << binarysearchUpper(s, target) << endl;
 return 0;
}


