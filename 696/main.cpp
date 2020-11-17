#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        const int str_len = s.size();
        if (str_len == 0) return 0;
        char now = s[0];
        for (int loop_i = 0; loop_i < str_len; ++loop_i) {
            if (s[loop_i] != now) {
                now = s[loop_i];
                int len = 1;
                while (loop_i + len <= str_len && loop_i - len >= 0) {
                    //cout << s[loop_i + len - 1] << " " << s[loop_i - len] << endl;
                    if (s[loop_i + len - 1] == now && s[loop_i - len] != now) len++;
                    else break;
                }
                result += len - 1;
                //cout << loop_i << " " << result << endl;
                
            }
        }
        return result;
    }
};


int main() {
    Solution s;
    cout << s.countBinarySubstrings("10101") << endl;
}