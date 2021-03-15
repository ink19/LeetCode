#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string getSmallestString(int n, int k) {
    std::string s(n, 'a');
    k -= n;
    for (int loop_i = 0; loop_i < n; ++loop_i) {
      if (k >= 25) {
        s[n - loop_i - 1] = 'z';
        k -= 25;
      } else {
        s[n - loop_i - 1] += k;
        k = 0;
      }
      if (k == 0) return s;
    }

    return s;
  }
};
