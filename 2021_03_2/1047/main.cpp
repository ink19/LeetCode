#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  string removeDuplicates(string S) {
    int S_len = S.size();
    if (S_len < 2) return S;
    for (int loop_i = 0; loop_i < S_len - 1; ++loop_i) {
      if (S[loop_i] == S[loop_i + 1]) {
        S.erase(S.begin() + loop_i, S.begin() + loop_i + 2);
        S_len -= 2;
        loop_i -= 2;
        if (loop_i < -1) loop_i = -1;
      }
    }
    return S;
  }
};