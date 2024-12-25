#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  map<int, vector<int>> m;
  string s;
  int no1;
  while (getline(cin, s)) {
    if (!isdigit(s[0]))
      break;
    int x = 0;
    int len = (int)s.length();
    for (int i = 0; i < len; ++i) {
      if (s[i] == '|') {
        no1 = stoi(s.substr(x, i));
        x = i + 1;
        break;
      }
    }
    m[stoi(s.substr(x, len))].push_back(no1);
  }
  // Print the map
  for (const auto &pair : m) {
    std::cout << "Key = " << pair.first << " : ";

    // 'pair.second' is the vector<int>
    for (int val : pair.second) {
      std::cout << val << " ";
    }

    std::cout << "\n"; // new line after printing the vector
  }
  no1 = 0;
  while (getline(cin, s)) {
    vector<int> line;
    if (!isdigit(s[0]))
      break;
    while (s.find(',') != string::npos) {
      line.push_back(stoi(s.substr(0, s.find(','))));
      s.erase(0, s.find(',') + 1);
    }
    line.push_back(stoi(s));
    cout << "line: ";
    for (int x : line) {
      cout << x << '\t';
    }
    auto printv = [&](vector<int> a) {
      for (int x : a) {
        cout << x << '\t';
      }
      cout << '\n';
    };
    cout << '\n';
    auto checkLine = [&](vector<int> l) {
      pair<bool, pair<int, int>> p;
      pair<int, int> inp;
      int len = (int)l.size();
      for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
          // cout << "i= ";
          // printv(m[l[i]]);
          // cout << " j=" << l[j] << " find = "
          //      << (find(m[l[i]].begin(), m[l[i]].end(), l[j]) ==
          //          m[l[i]].end());
          if (find(m[l[i]].begin(), m[l[i]].end(), l[j]) != m[l[i]].end()) {
            p.first = false;
            inp.first = i;
            inp.second = j;
            p.second = inp;
            return p;
          }
        }
      }
      p.first = true;
      return p;
    };
    pair<bool, pair<int, int>> p = checkLine(line);
    if (!p.first) {
      while (p.second.first <= line.size()) {
        iter_swap(line.begin() + p.second.first,
                  line.begin() + p.second.second);
        printv(line);
        p = checkLine(line);
        if (p.first)
          break;
      }
      if (p.first) {
        no1 += *(line.begin() + (line.size() / 2));
      }
    }
  }
  cout << no1;
  return 0;
}
