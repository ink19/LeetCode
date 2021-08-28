#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        const int piles_len = piles.size();
        int result = 0;
        std::sort(piles.begin(), piles.end());
        for (int loop_i = 0; loop_i < piles_len / 3; ++loop_i) {
            result += piles[piles_len - 1 - (1 + loop_i * 2)];
        }
        return result;
    }
};