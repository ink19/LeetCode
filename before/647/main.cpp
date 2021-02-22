#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        const int s_len = s.size();
        int Q[1000][1000];
        int result = s_len;
        for (int loop_i = 0; loop_i < s_len; ++loop_i) {
            for (int loop_j = 0; loop_j < s_len; ++loop_j) {
                Q[loop_i][loop_j] = 0;
            }
        }
        for (int loop_i = 0; loop_i < s_len; ++loop_i) Q[loop_i][loop_i] = 1;
        for (int loop_i = 0; loop_i < s_len - 1; ++loop_i) {
            if (s[loop_i] == s[loop_i + 1]) {
                Q[loop_i][loop_i + 1] = 1;\
                result += 1;
            }
        }

        for (int loop_i = 2; loop_i < s_len; ++loop_i) {
            for (int loop_j = 0; loop_j < s_len; ++loop_j) {
                const int last = loop_j + loop_i;
                if (last >= static_cast<int>(s.size())) break;
                const int begin = loop_j;
                if(Q[begin + 1][last - 1] == 1 && s[begin] == s[last]) {
                    Q[begin][last] = 1;
                    result += 1;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    std::cout <<s.countSubstrings("aaaaa") << std::endl;
}