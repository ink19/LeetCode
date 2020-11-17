#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &A) {
    size_t A_len = A.size();
    int index = 0;
    for (int loop_i = 1; loop_i < A_len; loop_i += 2) {
      if (A[loop_i] % 2 == 0) {
        int temp = A[loop_i];
        A[loop_i] = A[index];
        A[index] = temp;
        index += 2;
        loop_i -= 2;
      } 
    }
    return A;
  }
};