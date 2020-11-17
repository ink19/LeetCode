#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>
using namespace std;



class Solution {
public:
    int format(string &num1) {
        const int num1_len = num1.size();
        int carry = 0;
        for (int loop_i = 0; loop_i < num1_len; ++loop_i) {
            num1[loop_i] += carry;
            carry = num1[loop_i] / 10;
            num1[loop_i] %= 10;
        }
        return 0;
    }

    int add(string &num1, string &num2, int up) {
        const int num2_len = num2.size();
        for (int loop_i = 0; loop_i < num2_len; ++loop_i) {
            num1[loop_i + up] += num2[loop_i];
        }
        format(num1);
        return 0;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        const int num1_len = num1.size();
        const int num2_len = num2.size();
        string result(300, '\0');
        std::reverse(num1.begin(), num1.end());
        for (int loop_i = 0; loop_i < num1_len; ++loop_i) {
            num1[loop_i] -= '0';
        }
        for (int loop_i = 0; loop_i < num2_len; ++loop_i) {
            num2[loop_i] -= '0';
        }
        for (int loop_i = 0; loop_i < num2_len; ++loop_i) {
            string temp(num1_len, '\0');
            for (int loop_j = 0; loop_j < num1_len; ++loop_j) {
                temp[loop_j] = num1[loop_j] * num2[loop_i];
            }
            // std::cout << num2_len - loop_i - 1 << std::endl;
            add(result, temp, num2_len - loop_i - 1);
        }

        int result_len = 0;
        for (result_len = 299; result_len >= 0; --result_len) {
            if (result[result_len] != 0) break;
        }

        string final_result = result.substr(0, result_len + 1);
        std::reverse(final_result.begin(), final_result.end());
        for (int loop_i = 0; loop_i < final_result.size(); ++loop_i) {
            final_result[loop_i] += '0';
        }
        return final_result;
    }
};

int main() {
    
    return 0;
}