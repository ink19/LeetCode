#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max_index = 0, max_length = 0;
        const int str_len = s.size();
        for (int loop_i = 0; loop_i < str_len * 2; ++loop_i) {
            int start_index = loop_i / 2;
            int is_2 = loop_i % 2;
            int now_len = is_2;
            for (int loop_j = 1; loop_j < str_len; ++loop_j) {
                if (loop_j > start_index || loop_j + start_index > str_len) break;
                if (is_2) {
                    if (s[start_index - loop_j] == s[start_index + loop_j]) now_len+=2;
                    else break;
                } else {
                    if (s[start_index - loop_j] == s[start_index + loop_j - 1]) now_len+=2;
                    else break;
                }
            }
            if (now_len > max_length) {
                max_index = start_index;
                max_length = now_len;
            }
        }
        if (max_length%2 == 0) {
            return s.substr(max_index - max_length/2, max_length);
        } else {
            return s.substr(max_index - max_length/2, max_length);
        }
    }
};


int main() {
    Solution s;
    std::cout << s.longestPalindrome("babad") << endl;
    return 0;
}