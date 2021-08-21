#include <string>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int A_n = 0;
        int L_n = 0;
        const int s_len = s.size();
        for (int loop_i = 0; loop_i < s_len; ++loop_i) {
            if (s[loop_i] == 'L') {
                L_n++;
                if (L_n >= 3) return false;
                continue;
            }
            L_n = 0;
            if (s[loop_i] == 'A') {
                A_n++;
            }
        }
        if (A_n >= 2) {
            return false;
        }
        return true;
    }
};