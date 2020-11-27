#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    const int nums_len = A.size();
    unordered_map<int, int> num_map;
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      for (int loop_j = 0; loop_j < nums_len; ++loop_j) {
        num_map[A[loop_i] + B[loop_j]]++;
      }
    }
    
    int result = 0;
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      for (int loop_j = 0; loop_j < nums_len; ++loop_j) {
        if (num_map.count(-C[loop_i] - D[loop_j]) > 0) {
          result += num_map[-C[loop_i] - D[loop_j]];
        }
      }
    }
    return result;
  }
};
