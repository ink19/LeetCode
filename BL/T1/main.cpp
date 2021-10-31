#include <iostream>
#include <stdio.h>
#include <cmath>

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        double result = 0;
        double temp_result = n;
        for (int loop_i = 0; loop_i < m; ++loop_i) {
            result += temp_result;
            temp_result = std::pow(temp_result, 0.5);
        }
        printf("%.2lf\n", result);
    }
    return 0;
}