#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  int findRotateSteps(string ring, string key) {
    const size_t ring_len = ring.size();
    const size_t key_len = key.size();
    int dp_table[101][101];
    for (int loop_i = 0; loop_i < 101; ++loop_i) {
      for (int loop_j = 0; loop_j < 101; ++loop_j) {
        dp_table[loop_i][loop_j] = 1;
      }
    }

    for (int loop_i = 0; loop_i < ring_len; ++loop_i) {
      dp_table[0][loop_i] = std::min({loop_i, static_cast<int>(ring_len - loop_i)}) + 1;
    }

    for (int loop_i = 1; loop_i < key_len; ++loop_i) {
      for (int loop_j = 0; loop_j < ring_len; ++loop_j) {
        int min_roll = 1e9;
        for (int loop_k = 0; loop_k < ring_len; ++loop_k) {
          if (ring[loop_k] == key[loop_i - 1]) {
            int roll_n = std::abs(loop_j - loop_k);
            min_roll = std::min({min_roll, roll_n + dp_table[loop_i - 1][loop_k], static_cast<int>(ring_len - roll_n + dp_table[loop_i - 1][loop_k])});
          }
        }
        min_roll += 1;
        dp_table[loop_i][loop_j] = min_roll;
      }
    }
    int result = 1e9;

    for (int loop_i = 0; loop_i < ring_len; ++loop_i) {
      if (ring[loop_i] == key[key_len - 1]) {
        if (result > dp_table[key_len - 1][loop_i]) {
          result = dp_table[key_len - 1][loop_i];
        }
      }
    }
    return result;
  }
};


int main() {
  Solution s;
  std::cout << s.findRotateSteps("godding", "gd") << std::endl;
  return 0;
}