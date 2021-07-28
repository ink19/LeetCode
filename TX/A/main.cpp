#include <iostream>
#include <vector>

int main () {
    int T = 0;
    int n, k;
    int a[200];
    std::scanf("%d", &T);
    while (T--) {
        std::scanf("%d %d", &n, &k);
        for (int loop_i = 0; loop_i < n; ++loop_i) {
            std::scanf("%d", a + loop_i);
        }
        for (int loop_i = 0; loop_i < n; ++loop_i) {
            int temp_b = 0;
            std::scanf("%d", &temp_b);
            if (loop_i == 0) {
                a[loop_i] += temp_b;
            } 
        }
        int result = 1;
        for (int loop_i = 1; loop_i < n; ++loop_i) {
            if (a[loop_i] > a[0]) result++;
        }
        if (result <= k) {
            std::printf("Yes\n");
        } else {
            std::printf("No\n");
        }
    }
    return 0;
}