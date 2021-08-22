#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        const int s_len = s.size();
        if (s_len == 1) return 0;
        int has_one = 0;
        int result = 0;
        for (int loop_i = s_len - 1; loop_i >= 1; --loop_i) {
            if (has_one) {
                if (s[loop_i] == '0') {
                    result += 2;
                } else {
                    result += 1;
                }
            } else {
                if (s[loop_i] == '0') {
                    result += 1;
                } else {
                    result += 2;
                    has_one = 1;
                }
            }
        }
        if (has_one) {
            result += 1;
        } 
        return result;
    }
};