#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char stack[10000];
    int stack_len = 0;
    bool isValid(string s) {
        const int str_len = s.size();
        for (int loop_i = 0; loop_i < str_len; ++loop_i) {
            if (s[loop_i] == '(' || s[loop_i] == '[' || s[loop_i] == '{') {
                stack[stack_len++] = s[loop_i];
            } else {
                if (stack_len <= 0) return false;
                if (s[loop_i] == ')') {
                    if (stack[--stack_len] != '(') return false;
                }
                if (s[loop_i] == '}') {
                    if (stack[--stack_len] != '{') return false;
                }
                if (s[loop_i] == ']') {
                    if (stack[--stack_len] != '[') return false;
                }
            }
        }
        if (stack_len != 0) return false;
        return true;
    }
};
int main() {
    Solution s;
    std::cout << s.isValid("[]())") << std::endl;
}