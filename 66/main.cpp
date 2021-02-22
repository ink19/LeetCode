#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int dig_len = digits.size();
    digits[dig_len - 1]++;
    for (int loop_i = dig_len - 1; loop_i >= 0; --loop_i) {
      if (digits[loop_i] >= 10) {
        digits[loop_i] -= 10;
        if (loop_i != 0) {
          digits[loop_i - 1]++;
        } else {
          digits.insert(digits.begin(), 1);
          break;
        }
      } else break;
    }
    return digits;
  }
};