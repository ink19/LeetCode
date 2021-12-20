#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  set<string> result;

  int permutation1(string s, int start) {
    if (start == s.size()) {
      result.insert(s);
      return 0;
    }
    
    const int s_len = s.size();
    for (int loop_i = start; loop_i < s_len; ++loop_i) {
      // if (start != loop_i && s.at(start) == s.at(loop_i)) continue;
      std::swap(s.at(start), s.at(loop_i));
      permutation1(s, start + 1);
      std::swap(s.at(start), s.at(loop_i));
    }
    return 0;
  }

  vector<string> permutation(string s) {
    permutation1(s, 0);
    return vector<string>(result.begin(), result.end());
  }
};