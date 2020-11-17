#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int flag = 0;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) flag = 1;
        long long ldividend = std::abs((long long)dividend);
        long long ldivisor = std::abs((long long)divisor);
        long long result = 0;
        int max_len = 0;
        while (ldividend >= (ldivisor << max_len)) max_len++;
        max_len--;

        while(ldividend >= ldivisor) {
            if (ldividend >= (ldivisor << max_len)) {
                ldividend -= (ldivisor << max_len);
                result += (((long long)1) << max_len);
                
            }
            max_len--;
            if (max_len < 0) break;
        }
        
        if (flag) result = -result;
        if (-(((long long)1) << 31) > result || ((((long long)1) << 31) - 1) < result) return ((((long long)1) << 31) - 1);
        else return result;
    }
};


int main() {
    Solution s;
    cout << s.divide(-2147483648, 1) << endl;
    return 0;
}