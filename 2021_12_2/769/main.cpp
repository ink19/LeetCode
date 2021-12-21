#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
  int split_arr(const vector<vector<std::pair<int, int>>>& dp, int begin, int end) {
    int len = end - begin;
    if (len == 0) return 0;
    if (len == 1) return 1;
    int max_result = 1;
    for (int loop_i = 1; loop_i < len; ++loop_i) {
      auto prev = dp[begin][begin + loop_i];
      auto last = dp[begin + loop_i][end];
      if (prev.second <= last.first) {
        int local_result = 0;
        local_result += split_arr(dp, begin, begin + loop_i);
        local_result += split_arr(dp, begin + loop_i, end);
        if (local_result > max_result)  max_result = local_result;
      }
    }
    return max_result;
  }
  int maxChunksToSorted(vector<int> &arr) {
    vector<vector<std::pair<int, int>>> dp(arr.size() + 1, vector<std::pair<int, int>>(arr.size() + 1, {0, 0}));
    for (int loop_i = 0; loop_i < arr.size(); ++loop_i) {
      dp[loop_i][loop_i + 1] = {arr[loop_i], arr[loop_i]};
    }
    for (int loop_i = 0; loop_i < arr.size(); ++loop_i) {
      for (int loop_j = 1; loop_j < arr.size(); ++loop_j) {
        int begin = loop_i;
        int end = loop_j + loop_i + 1;
        if (end > arr.size()) break;;
        auto last = dp[begin][end - 1];
        if (arr[end - 1] > last.second) last = {last.first, arr[end - 1]};
        if (arr[end - 1] < last.first) last = {arr[end - 1], last.second};
        dp[begin][end] = last;
      }
    }
    return split_arr(dp, 0, arr.size());
  }
};
