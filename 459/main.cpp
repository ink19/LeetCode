#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        const int strlen = s.size();
        for (int loop_i = 1; loop_i < strlen; ++loop_i) {
            if (strlen % loop_i) continue;
            const int num = strlen / loop_i;
            for (int loop_j = 1; loop_j < num; ++loop_j) {
                for (int loop_s = 0; loop_s < loop_i; ++loop_s) {
                    if (s[(loop_j - 1) * loop_i + loop_s] != s[loop_j * loop_i + loop_s]) {
                        goto next;
                    }
                }
            }
            return true;
            next:;
        }
        return false;
    }
};

int main() {
    Solution s;
    std::cout << s.repeatedSubstringPattern("a") << std::endl;
}