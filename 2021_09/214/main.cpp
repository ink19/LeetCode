#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        const int s_len = s.size();
        std::vector<int> kmp_data(s_len, -1);

        int last_position = - 1;
        for (int loop_i = 1; loop_i < s_len; ++loop_i) {
            while (last_position > - 1 && s[last_position + 1] != s[loop_i]) {
                last_position = kmp_data[last_position];
            }

            if (s[last_position + 1] == s[loop_i]) {
                last_position = last_position + 1;
            }
            kmp_data[loop_i] = last_position;
        }
        int match_index = -1;
        for (int loop_i = 0; loop_i < s_len; ++loop_i) {
            while (match_index > - 1 && s[match_index + 1] != s[s_len - 1 - loop_i]) {
                match_index = kmp_data[match_index];
            }

            if (s[match_index + 1] == s[s_len - 1 - loop_i]) {
                match_index += 1;
            }
        }
        std::string sub_str = s.substr(match_index + 1);
        std::reverse(sub_str.begin(), sub_str.end());
        s = sub_str + s;

        return s;
    }
};

int main() {
    std::cout << Solution().shortestPalindrome("aacecaaa") << std::endl;
    return 0;
}