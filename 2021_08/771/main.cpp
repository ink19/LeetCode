#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        std::set<char> jewels_set(jewels.begin(), jewels.end());
        int result = 0;
        const int stones_size = stones.size();
        for (int loop_i = 0; loop_i < stones_size; ++loop_i) {
            if (jewels_set.find(stones[loop_i]) != jewels_set.end()) {
                result++;
            }
        }
        return result;
    }
};