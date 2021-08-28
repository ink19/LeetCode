#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int result = 0;
        int p = 0;
        int s_len = s.size();
        for (int loop = 0; loop < s_len; ++loop) {
            if (s[loop] == p + '0') {
                result++;
            }
            p = !p;
        }
        if (result < s_len - result) {
            return result;
        } else {
            return s_len - result;
        }
    }
};