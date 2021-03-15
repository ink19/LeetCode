#include <vector>

using namespace std;

class Solution {
public:
  int minArray(vector<int> &numbers) {
    int small_number = numbers.at(0);
    const int num_len = numbers.size();
    for (int loop_i = 0; loop_i < num_len; ++loop_i) {
      if (numbers[loop_i] < small_number) {
        small_number = numbers[loop_i];
      }
    }
    return small_number;
  }
};