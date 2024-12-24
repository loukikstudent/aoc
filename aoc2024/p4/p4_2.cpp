#include "bits/stdtr1c++.h"
#include <vector>

using namespace std;

const vector<pair<int, int>> dirs= {{-1,-1}, {-1,1}, {1,1}, {1,-1}};
int main (int argc, char *argv[]) {
  int H = 140;
  vector<string> a(H); 

  for(string& row: a){
    cin >> row;
  }

  int W = (int) a[0].length();
  
  int answer = 0;
  for (int row = 1; row < H - 1 ; row++){
    for (int col = 1; col < W -1 ; col++){
      if (a[row][col] == 'A'){
        string s;
        for (pair<int, int> dir : dirs){
          s += a[row + dir.first][col + dir.second];
        }
        if (s == "MMSS" || s == "SMMS" || s== "SSMM" || s == "MSSM"){
          answer +=1;
        }
      }
    }
  }
  cout << answer << '\n';
}
