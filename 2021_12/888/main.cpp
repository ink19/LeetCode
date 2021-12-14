#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
  vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes) {
    const int alice_len = aliceSizes.size();
    const int bob_len = bobSizes.size();
    const int alice_sum = std::accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
    const int bob_sum = std::accumulate(bobSizes.begin(), bobSizes.end(), 0);
    const int diff = alice_sum - bob_sum;
    std::sort(aliceSizes.begin(), aliceSizes.end());
    std::sort(bobSizes.begin(), bobSizes.end());
    for (int loop_i = 0; loop_i < alice_len; ++loop_i) {
      int wanted = aliceSizes[loop_i] - diff / 2;
      if (binary_search(bobSizes.begin(), bobSizes.end(), wanted)) {
        return {aliceSizes[loop_i], wanted};
      }
    }
    return {0, 0};
  }
};