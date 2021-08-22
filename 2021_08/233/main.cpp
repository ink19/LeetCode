#include <iostream>

class Solution {
public:
    int countDigitOne(int n) {
        int result = 0;
        long long loop_i = 1;
        int temp_n = n;
        while (temp_n) {
            int now_dig = temp_n % 10;
            if (now_dig == 1) {
                result += (n % loop_i) + 1;
            } 
            if (now_dig > 1) {
                result += loop_i;
            }

            result += (temp_n / 10) * loop_i;
            loop_i *= 10;
            temp_n /= 10;
        }
        return result;
    }
};