#include <any>
#include <bits/stdc++.h>

using namespace std;

bool isOk(vector<int> a){
  int k = (int) a.size();
  bool ok = true;
  bool only_inc = true;
  bool only_dec = true;
  for (int j=0;j<k-1;j++){
    int diff = a[j] - a[j+1];
    if(!(1<=abs(diff) && abs(diff) <=3)){
      ok = false;
      break;
    }
    if (diff > 0){
      only_dec = false;
    }
    if (diff < 0){
      only_inc = false;
    }
  }
  return ok && (only_inc || only_dec);
}


int main(){
  int n = 1000;
  int answer = 0;
  for (int i =0; i< n; i++){
    vector<int> a;
    while(true){
      int x;
      scanf("%d", &x);
      a.push_back(x);
      char c;
      scanf("%c", &c);
      if (c == '\n'){
        break;
      }
    }
    if (isOk(a)){
      answer++;
      continue;
    }
    bool anyOk=false;
    auto consider = [&](int i){
      vector<int> b = a;
      b.erase(b.begin()+i);
      if(isOk(b)){
        anyOk = true;
      };
    };
    int k = a.size();
    for (int i = 0;  i< k-1; i++) {
      int diff = a[i] - a[i+1];
      if ((abs(diff) < 1) | (abs(diff) > 3)){
        consider(i);
        consider(i+1);
        break;
      }
      if (i+2 < k ){
        int diff2 = a[i+1] - a[i+2];
        if ((diff > 0 ) != (diff2 > 0)){
          consider(i);
          consider(i+1);
          consider(i+2);
          break;
        }
      }
    }
    if (anyOk){
      answer++;
    }
    
  }
  printf("%d\n", answer);
}
