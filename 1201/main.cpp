#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long mgcd(long long a,long long b) //求两个数的最大公约数
{
    return b ? mgcd(b,a%b):a;
}
long long mlcm(long long m,long long g)  //求两个数的最小公倍数
{
    return m/mgcd(m,g)*g;
}

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long begin = 0, end = 2 * 10e9;
        long long mid = (begin + end) >> 1;
        long long ab = mlcm(a, b);
        long long ac = mlcm(a, c);
        long long bc = mlcm(b ,c);
        long long abc = mlcm(ab, c);
        while (1) {
            mid = (begin + end) >> 1;
            long long mid_index = 0;
            mid_index += mid/a;
            mid_index += mid/b;
            mid_index += mid/c;
            mid_index -= mid/ab;
            mid_index -= mid/bc;
            mid_index -= mid/ac;
            mid_index += mid/abc;
            if (n == mid_index) break;
            else if (n > mid_index) {
                begin = mid + 1;
            } else {
                end  = mid - 1;
            }
        }
        return mid - std::min(mid % a, std::min(mid % b, mid % c));
    }
};

int main() {
    Solution s;
    std::cout << s.nthUglyNumber(1000000000, 2, 217983653, 336916467) << std::endl;
}