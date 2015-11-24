#include<vector>
#include<string>
#include<iostream>

using namespace std;

class KMP {
public:
  KMP(){};
  ~KMP(){};
  size_t KMPsearch(const string& pattern, const string& text);
private:
  vector<int> partialMatchTable;
  void buildTable(const string& pattern);
};

void KMP::buildTable(const string& pattern) {
  // first two elements are -1 and 0
  partialMatchTable.push_back(-1);
  partialMatchTable.push_back(0);
  
  size_t i = 0;
  size_t j = 2;

  while(j < pattern.size()) {
    if(pattern[i] != pattern[j-1]) {
      partialMatchTable.push_back(0);
      i = 0;
    }
    else {
      partialMatchTable.push_back(1 + partialMatchTable.back());
      i++;
    }
    j++;
  }
}

size_t KMP::KMPsearch(const string& pattern, const string& text) {
  buildTable(pattern);
  cout << "Partial Match Table is:" << endl;
  for(vector<int>::iterator iter = partialMatchTable.begin(); iter != partialMatchTable.end(); iter++) {
    cout << *iter << " ";
  }
  cout << endl;

  int i = 0;
  size_t j = 0;

  while(j < text.size()) {
    if(i == pattern.size()-1) {
      return (j - i);
    }
    if(pattern[i] == text[j]) {
      i++;
      j++;
    } else {
      i = partialMatchTable[i];
      if(i == -1)  j++; 
    }
  }
  return (text.size()-1);
}

int main() {
  KMP kmp;
  string pattern;
  string text;
  cout << "Input your pattern:" << endl;
  getline(cin, pattern);
  cout << "Input your text: " << endl;
  getline(cin, text);
  cout << "Idx of " << pattern << " in " << text << " is:" << endl;
  cout << kmp.KMPsearch(pattern, text) << endl;
  return 1;
}


