#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    if (k == 0) return {{}};
    vector<vector<int>> result;
    if (n == k) {
      vector<int> result_1;
      for (int loop_i = 1; loop_i <= n; ++loop_i) {
        result_1.push_back(loop_i);
      }
      result.push_back(result_1);
      return result;
    }
    result = combine(n - 1, k);
    auto temp_result2 = combine(n - 1, k - 1);
    for (auto temp_result2_item : temp_result2) {
      temp_result2_item.push_back(n);
      result.push_back(temp_result2_item);
    }
    return result;
  }
};

int main() {}