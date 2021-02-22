#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        const int str_len = s.size();
        int max_len = 0;
        for (int loop_i = str_len - 1; loop_i >= 0; loop_i--) {
            int end = loop_i;
            int begin = 0;
            while (s[begin] == s[end]) {
                if (begin >= end) {
                    goto get_it;
                } else {
                    begin++;
                    end--;
                }
            }
            continue;
            get_it:;
            max_len = loop_i;
            break;
        }
        string temp_string = s.substr(max_len + 1);
        std::reverse(temp_string.begin(), temp_string.end());
        return temp_string + s;
    }
}; 

int main() {
    Solution s;
    std::cout << s.shortestPalindrome("") << std::endl;
}