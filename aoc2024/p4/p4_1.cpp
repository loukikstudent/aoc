#include "bits/stdtr1c++.h"

using namespace std;

int main (int argc, char *argv[]) {
  int H = 140;
  vector<string> a(H); 

  for(string& row: a){
    cin >> row;
  }

  int W = (int) a[0].length();
  string TEMP = "XMAS";
  auto inside = [&](int r, int c){
    return (0<=r && r<H  && 0<=c && c<W);
  };
  int answer = 0;
  for (int row = 0; row < H ; ++row){
    for (int col = 0; col < W ; ++col){
      if (a[row][col] == 'X'){
       for (int drow =-1; drow<= 1; ++drow){
         for (int dcol = -1; dcol<=1;++dcol){
           if (drow == 0 && dcol == 0){
             continue;
           }
           bool allOkay = true;
           for(int i=0; i<4; ++i){
             int r2 = row + drow * i;
             int c2 = col + dcol * i;
             if (inside(r2, c2) && (a[r2][c2] == TEMP[i])){

             }
             else{
               allOkay = false;
               break;
             }
           }
           answer += allOkay;
         }
       } 
      }
    }
  }
  cout << answer;
}
