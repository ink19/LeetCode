#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
  std::set<int> jiaoji(std::vector<int>& num1, std::vector<int>& num2) {
    std::set<int> result;
    for (int loop_i = 0; loop_i < num1.size(); ++loop_i) {
      if (std::binary_search(num2.begin(), num2.end(), num1[loop_i])) {
        result.insert(num1[loop_i]);
      }
    }
    return result;
  }

  std::set<int> bingji(const std::set<int>& a, const std::set<int>& b) {
    std::set<int> result = a;
    result.insert(b.begin(), b.end());
    return result;
  }

  vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    std::sort(nums3.begin(), nums3.end());
    auto result = bingji(jiaoji(nums1, nums2), bingji(jiaoji(nums1, nums3), jiaoji(nums2, nums3)));
    return vector<int>(result.begin(), result.end());
  }
};