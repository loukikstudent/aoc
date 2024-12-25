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
    bool isOkay = true;
    int incorrectIndex;
    int len = (int)line.size();
    for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j < len; ++j) {
        // cout << "i= ";
        // printv(m[line[i]]);
        // cout << " j=" << line[j] << " find = "
        //      << (find(m[line[i]].begin(), m[line[i]].end(), line[j]) ==
        //          m[line[i]].end());
        if (find(m[line[i]].begin(), m[line[i]].end(), line[j]) !=
            m[line[i]].end()) {
          isOkay = false;
          break;
        }
      }
      if (!isOkay) {
        break;
      }
    }
    if (isOkay) {
      cout << "ok : ";
      for (int x : line) {
        cout << x << '\t';
      }
      cout << '\n';
      cout << "middle  " << *(line.begin() + (line.size() / 2))
           << "  no1 = " << no1 << '\n';
      no1 += *(line.begin() + (line.size() / 2));
      cout << "after addition" << no1 << '\n';
    }
  }
  cout << no1;
  return 0;
}
