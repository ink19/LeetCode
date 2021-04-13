#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
  int nthUglyNumber(int n) {
    std::vector<int> data = {1};
    int index_2 = 0;
    int index_3 = 0;
    int index_5 = 0;
    for (int loop_i = 1; loop_i < n; ++loop_i) {
      int mul_2 = data[index_2] * 2;
      int mul_3 = data[index_3] * 3;
      int mul_5 = data[index_5] * 5;
      int min_mul = std::min({mul_2, mul_3, mul_5});
      data.push_back(min_mul);
      if (min_mul == mul_2) {
        index_2++;
      }  
      if(min_mul == mul_3) {
        index_3++;
      } 
      if(min_mul == mul_5) {
        index_5++;
      }
    }
    return data[n - 1];
  }
};

int main() {
  Solution s;
  s.nthUglyNumber(20);
  return 0;
}