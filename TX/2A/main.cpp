#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

int main() {
    int T;
    std::scanf("%d", &T);
    while (T--) {
        long long n, k;
        std::scanf("%lld%lld", &n, &k);
        std::vector<int> data(n, 0);
        for (long long loop_i = 0; loop_i < n; ++loop_i) {
            std::scanf("%d", &data[loop_i]);
        }
        if (k >= n) {
            bool isSame = true;
            for (long long loop_i = 0; loop_i < n - 1; ++loop_i) {
                if (data[loop_i] != data[loop_i + 1]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) {
                printf("%lld %d\n", k, data[0]);
            } else {
                printf("INF\n");
            }
            continue;
        }
        int same_num = -1;
        int same_n = 0;
        bool isGet = false;
        for (long long loop_i = 0; loop_i < 2 * n; ++loop_i){
            if (data[loop_i%n] == same_num) {
                same_n++;
            } else {
                same_num = data[loop_i%n];
                same_n = 1;
            }
            if (same_n == k) {
                printf("%lld %d\n", loop_i + 1, same_num);
                isGet = true;
                break;
            }
        }
        if (!isGet) {
            printf("INF\n");
        }
    }
}