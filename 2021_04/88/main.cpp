#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int loop_i = m - 1, loop_j = n - 1;
    int loop_k = m + n - 1;
    for (; loop_k >= 0; --loop_k) {
      if (loop_i < 0) {
        nums1[loop_k] = nums2[loop_j];
        loop_j--;
        continue;
      }
      if (loop_j < 0) {
        nums1[loop_k] = nums1[loop_i];
        loop_i--;
        continue;
      }
      if (nums1[loop_i] > nums2[loop_j]) {
        nums1[loop_k] = nums1[loop_i];
        loop_i--;
        continue;
      } else {
        nums1[loop_k] = nums2[loop_j];
        loop_j--;
        continue;
      }
    }
  }
};