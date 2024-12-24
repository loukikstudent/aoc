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
  regex pattern("mul\\(([0-9]{1,3})\\,([0-9]{1,3})\\)");
  int value=0;
  for(sregex_iterator it(s.begin(), s.end(), pattern), end_it; it != end_it; ++it){
    smatch res = *it;
    value += (stoi(res[1]) * stoi(res[2]));
  }
  cout << value << '\n';

}
