#include <iostream>
#include <vector>
#include <cstdio>
#include <map>

int main() {
    int T;
    std::scanf("%d", &T);
    while (T--) {
        int n;
        std::scanf("%d", &n);
        std::vector<std::map<int, int>> path(n, std::map<int, int>());
        for (int loop_i = 0; loop_i < n - 1; ++loop_i) {
            int a, b, c;
            std::scanf("%d %d %d", &a, &b, &c);
            path[a - 1][b - 1] = c;
        }
        
    }
}