#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        vector<int> result;
        const int A_len = A.size();
        if (A_len == 0 || A_len == 1) return 0;
        const int str_len = A.at(0).size();
        for (int loop_i = 0; loop_i < str_len; ++loop_i) {
            for (int loop_j = 1; loop_j < A_len; ++loop_j) {
                if (A[loop_j][loop_i] < A[loop_j - 1][loop_i]) {
                    goto ok;
                } 
            }
            result.push_back(loop_i);
            ok:;
        }
        return str_len - result.size();
    }
};