#include <iostream>
#include <stdio.h>

int is_shui(int data) {
    int temp_data = data;
    int temp_sum = 0;
    while (temp_data) {
        int n = temp_data % 10;
        temp_sum += n * n * n;
        temp_data /= 10;
    }
    if (temp_sum == data) {
        return 1;
    }
    return 0;
}

int main() {
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        int is_out = 0;
        for (int loop_i = m; loop_i <= n; ++loop_i) {
            if (is_shui(loop_i)) {
                is_out += 1;
                printf("%d ", loop_i);
            }
        }
        if (!is_out) {
            printf("no\n");
        } else {
            printf("\n");
        }
    }
    return 0;
}