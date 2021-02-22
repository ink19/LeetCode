#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
      int slow_pointer = 0;
      int quick_pointer = 0;
      int max_len = 0;
      int left_K = K;
      const int A_len = A.size();
      for (int loop_i = 0; loop_i < A_len; ++loop_i) {
        quick_pointer = loop_i;
        if (A[loop_i] == 0) {
          if (left_K > 0) {
            left_K--;
          } else {
            while (A[slow_pointer] == 1 && slow_pointer <= quick_pointer) {
              slow_pointer++;
            }
            if (slow_pointer > quick_pointer) {
              return -1;
            }
            slow_pointer++;
          }
        }
        if (max_len < quick_pointer - slow_pointer + 1) {
          max_len = quick_pointer - slow_pointer + 1;
        } 
      }
      return max_len;
    }
};