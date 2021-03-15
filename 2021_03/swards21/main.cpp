#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> exchange(vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), [](int d, int c) {
      return (c%2) < (d%2);
      // return d < c;
    });
    return nums;
  }
};

int main () {
  vector<int> data = {1, 2, 3, 4};
  Solution s;
  auto out = s.exchange(data);
  for (auto i : out) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}