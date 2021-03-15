#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string reverseLeftWords(string s, int n) {
    std::string result;
    result.append(s.begin() + n, s.end());
    result.append(s.begin(), s.begin() + n);
    return result;
  }
};