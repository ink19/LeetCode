#include <iostream>
#include <vector>
#include <cstdio>

long long jiecheng(long long n) {
    if (n == 0) return 1;
    long long result = 1;
    for (long long loop_i = 1; loop_i <= n; ++loop_i) {
        result *= loop_i;
        result %= 1000000007;
    }
    return result;
}

int main() {
    int T;
    std::scanf("%d", &T);
    while (T--) {
        char c = 0;
        long long zero_n = 0;
        long long one_n = 0;
        while (c != '0' && c!= '1') c = getchar();
        while (c == '0' || c == '1') {
            if (c == '0') zero_n++;
            else one_n++;
            c = getchar();
        }
        long long n = zero_n + one_n;
        long long result = (2 * n - one_n) * (one_n + 1) / 2;
        result %= 1000000007;
        result *= jiecheng(n - 1);
        result %= 1000000007;
        std::printf("%lld\n", result);
    }
}