#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
  int first_di(int data) {
    while (data >= 10) data /= 10;
    return data;
  }
  string minNumber(vector<int> &nums) {
    int min_index = 0;
    for (int loop_i = 0; loop_i < nums.size(); ++loop_i) {
      if (nums[loop_i] != 0) {
        if (first_di(nums[loop_i]) < first_di(nums[min_index])) {
          min_index = loop_i;
        }
      }
    }
    std::swap(nums[min_index], nums[0]);
    std::sort(nums.begin() + 1, nums.end(), [](int a, int b) {
      return (to_string(a) + to_string(b)) > (to_string(b) + to_string(a));
    });
    string result = std::accumulate(nums.begin(), nums.end(), string(), [](string s, int data) {
      return s + std::to_string(data);
    });
    return result;
  }
};

