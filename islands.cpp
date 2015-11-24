#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char> >& grid) {
    int res = 0;
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(grid[i][j] == '1') {
          res++;
          findBoundary(grid, i, j);
        }
      }
    }
    return res;
  }

  void findBoundary(vector<vector<char> >& grid, int i, int j) {
    if(grid[i][j] == '1') grid[i][j] = 0;
    else return;
    if(i+1 < grid.size()) findBoundary(grid, i+1, j);
    if(j+1 < grid[0].size()) findBoundary(grid, i, j+1);
    if(i >= 1) findBoundary(grid, i-1, j);
    if(j >= 1) findBoundary(grid, i,j -1);
  }
};

int main() {
  Solution solution;
  vector<vector<char> > grid(3, vector<char> {'1','0','1'});
  cout << "grid is" << endl;
  for(vector<vector<char> >::iterator a = grid.begin(); a != grid.end(); a++) {
    for(vector<char>::iterator b = a->begin(); b != a->end(); b++) {
      cout << *b;
    }
    cout << endl;
  }
  cout << "number of islands is " << endl;
  cout << solution.numIslands(grid) << endl;
}
