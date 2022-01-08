#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    std::vector<int> result = {0, 1};
    for (int loop_i = 1; loop_i < n; ++loop_i) {
      std::vector<int> new_end;
      for (auto iter = result.rbegin(); iter != result.rend(); ++iter) {
        new_end.push_back(*iter | (1 << (loop_i)));
      }
      result.insert(result.end(), new_end.begin(), new_end.end());
    }
    return result;
  }
};