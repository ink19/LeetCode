#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    std::sort(C.begin(), C.end());
    std::sort(D.begin(), D.end());
    vector<pair<int, int>> nA;
    vector<pair<int, int>> nB; 
    vector<pair<int, int>> nC;
    vector<pair<int, int>> nD;
    int num_len = static_cast<int>(A.size());
        
    if (num_len == 0) return 0;
    int temp_num = A[0];
    int temp_num_num = 1;
    for (int loop_i = 1; loop_i < num_len; ++loop_i) {
      if (temp_num == A[loop_i]) {
        temp_num_num++;
      } else {
        nA.push_back({temp_num, temp_num_num});
        temp_num = A[loop_i];
        temp_num_num = 1;
      }
    }
    nA.push_back({temp_num, temp_num_num});

    
    temp_num = B[0];
    temp_num_num = 1;
    for (int loop_i = 1; loop_i < num_len; ++loop_i) {
      if (temp_num == B[loop_i]) {
        temp_num_num++;
      } else {
        nB.push_back({temp_num, temp_num_num});
        temp_num = B[loop_i];
        temp_num_num = 1;
      }
    }

    nB.push_back({temp_num, temp_num_num});


    temp_num = C[0];
    temp_num_num = 1;
    for (int loop_i = 1; loop_i < num_len; ++loop_i) {
      if (temp_num == C[loop_i]) {
        temp_num_num++;
      } else {
        nC.push_back({temp_num, temp_num_num});
        temp_num = C[loop_i];
        temp_num_num = 1;
      }
    }

    nC.push_back({temp_num, temp_num_num});

    
    temp_num = D[0]; 
    temp_num_num = 1;
    for (int loop_i = 1; loop_i < num_len; ++loop_i) {
      if (temp_num == D[loop_i]) {
        temp_num_num++;
      } else {
        nD.push_back({temp_num, temp_num_num});
        temp_num = D[loop_i];
        temp_num_num = 1;
      }
    }

    nD.push_back({temp_num, temp_num_num});

    int result = 0;
    for (int loop_i = 0; loop_i < nA.size(); ++loop_i) {
      for (int loop_j = 0; loop_j < nB.size(); ++loop_j) {
        int begin = 0;
        int end = nD.size() - 1;
        while (begin < nC.size() && end > -1) {
          if (nA[loop_i].first + nB[loop_j].first + nC[begin].first + nD[end].first == 0) {
            result += nA[loop_i].second * nB[loop_j].second * nC[begin].second * nD[end].second;
            begin++;
          } else if (nA[loop_i].first + nB[loop_j].first + nC[begin].first + nD[end].first > 0) {
            end--;
          } else {
            begin++;
          }
        }
      }
    }
    return result;
  }
};
