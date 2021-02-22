#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minKBitFlips(vector<int> &A, int K) {
    int A_len = A.size();
    vector<int> rediff(A_len, 0);
    int recount = 0;
    for (int loop_i = 0; loop_i < A_len; ++loop_i) {
      if (loop_i - K >= 0 && rediff[loop_i - K] == 1) recount -= 1;
      if (loop_i + K > A_len) {
        if ((A[loop_i] + recount) % 2 == 0) {
          std::cout << loop_i << " :" << A[loop_i] + recount << std::endl;
          return -1;
        } 
      } else {
        if ((A[loop_i] + recount) % 2 == 0) {
          rediff[loop_i] = 1;
          recount += 1;
        }
      }
    }
    recount = 0;
    for (int loop_i = 0; loop_i < A_len; ++loop_i) {
      recount += rediff[loop_i];
    }
    return recount;
  }
};

int main() {
  Solution s;
  vector<int> aa = {0,0,0,1,0,1,1,0};
  cout << s.minKBitFlips(aa, 3) <<  std::endl;
  return 0;
}