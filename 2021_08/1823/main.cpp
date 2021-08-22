#include <vector>

class Solution {
public:
    int findTheWinner(int n, int k) {
        std::vector<int> quan(n, 0);
        for (int loop_i = 0; loop_i < n; ++loop_i) {
            quan[loop_i] = loop_i;
        }
        int begin = 0;
        k -= 1;
        while (quan.size() != 1) {
            begin += k;
            begin %= quan.size();
            quan.erase(quan.begin() + begin);
        }
        return *quan.begin() + 1;
    }
};