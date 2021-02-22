#include <string>
#include <iostream>
#include <ctype.h>
#include <limits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        const int str_len = str.size();
        int begin_index = 0;
        int is_ng = 0;
        for (int loop_i = 0; loop_i < str_len; ++loop_i) {
            if (str[loop_i] == ' ') continue;
            if (str[loop_i] == '-') {
                is_ng = 1;
                begin_index = loop_i + 1;
                break;
            }
            if (str[loop_i] == '+') {
                begin_index = loop_i + 1;
                break;
            }
            if (isdigit(str[loop_i])) {
                begin_index = loop_i;
                break;
            }
            return 0;
        }
        long long result = 0;
        for (int loop_i = begin_index; loop_i < str_len; ++loop_i) {
            if (isdigit(str[loop_i])) {
                result *= 10;
                result += str[loop_i] - '0';
                if (is_ng) {
                    if (result > (((long long)1) << 31)) {
                        return -(((long long)1) << 31);
                    }
                } else {
                    if (result > (((long long)1) << 31) - 1) {
                        return (((long long)1) << 31) - 1;
                    }
                }
            } else {
                break;
            }
        }
        if (is_ng) return -result;
        else return result;
    }
};


int main() {
    Solution s;
    cout << s.myAtoi("4193 with words") << endl;
    return 0;
}