#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int str_len = s.size();
        int max = 0;
        int sid_len = 0;
        std::string sid_s = "";
        for (int loop_i = 0; loop_i < str_len; ++loop_i) {
            //sid_len = sid_s.size();
            int loop_j;
            for (loop_j = 0; loop_j < sid_len; ++loop_j) {
                if (sid_s[loop_j] == s[loop_i]) {
                    break;
                }
            }
            sid_s.push_back(s[loop_i]);
            if (sid_len != loop_j) {
                sid_s = sid_s.substr(loop_j + 1);
            }
            sid_len = sid_s.size();
            if (sid_len > max) max = sid_len;
        }
        return max;
    }
};

int main() {
    Solution s;
    std::cout << s.lengthOfLongestSubstring("") << std::endl;
}