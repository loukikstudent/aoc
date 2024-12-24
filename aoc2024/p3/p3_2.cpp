#include <bits/stdc++.h>
#include <cstdio>
#include <regex>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
  string s;
  char c;
  while (scanf("%c", &c) != EOF) {
    s += c;
  }
  regex pattern("mul\\(([0-9]{1,3})\\,([0-9]{1,3})\\)|do\\(\\)|don't\\(\\)");
  int value=0;
  bool disabled = false;
  for(sregex_iterator it(s.begin(), s.end(), pattern), end_it; it != end_it; ++it){
    smatch res = *it;
    if (res.str() == "don't()"){
      disabled = true;
      continue;
    }
    else if (res.str() == "do()"){
      disabled = false;
      continue;
    }
    if (!disabled){
     value += (stoi(res[1]) * stoi(res[2]));
    }
  }
  cout << value << '\n';

}
