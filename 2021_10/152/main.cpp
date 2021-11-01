#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    const int nums_len = nums.size();
    int max_data = nums[0];
    int nmax = nums[0];
    int nmin = nums[0];
    for (int loop_i = 1; loop_i < nums_len; ++loop_i){
      int tnmax = nmax;
      int tnmin = nmin;
      nmax = std::max({tnmax * nums[loop_i], tnmin * nums[loop_i], nums[loop_i]});
      nmin = std::min({tnmax * nums[loop_i], tnmin * nums[loop_i], nums[loop_i]});
      if (nmax > max_data) max_data = nmax;
    }
    return max_data;
  }
};

int main() {
  vector<int> data = {-4,-3,-2};
  std::cout << Solution().maxProduct(data) << std::endl; 
}