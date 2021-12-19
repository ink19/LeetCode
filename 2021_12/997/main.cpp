#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    std::vector<std::set<int>> trust_link(n);
    std::vector<int> trusted_link(n, 0);
    for (auto &item : trust) {
      trust_link[item[0]].insert(item[1]);
      trusted_link[item[1]]++;
    }
    for (int loop_i = 0; loop_i < n; ++loop_i) {
      if (trusted_link[loop_i] == n - 1 && trust_link[loop_i].size() == 0) {
        return loop_i;
      }
    }
    return -1;
  }
};