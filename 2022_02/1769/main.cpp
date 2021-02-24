#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<int> minOperations(string boxes) {
    const int boxes_len = boxes.size();
    vector<int> result(boxes_len, 0);
    for (int loop_i = 0; loop_i < boxes_len; ++loop_i) {
      int sum_step = 0;
      for (int loop_j = 0; loop_j < boxes_len; ++loop_j) {
        if (boxes[loop_j] == '1') {
          sum_step += std::abs(loop_j - loop_i);
        }
      }
      result[loop_i] = sum_step;
    }
    return result;
  }
};