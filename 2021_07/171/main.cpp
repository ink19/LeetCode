#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        long long base = 1;

        result = std::accumulate(columnTitle.rbegin(), columnTitle.rend(), 0, [&base](int result, char T) {
            result += (T - 'A' + 1) * base;
            base *= 26;
            return result;
        });

        return result;
    }
};