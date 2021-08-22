#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        const int satisfaction_len = satisfaction.size();
        std::sort(satisfaction.rbegin(), satisfaction.rend());
        int max_result = 0;
        int sum_it = 0;
        for (int loop_i = 0; loop_i < satisfaction_len; ++loop_i) {
            if (max_result > max_result + sum_it + satisfaction[loop_i]) {
                break;
            }
            max_result = max_result + sum_it + satisfaction[loop_i];
            sum_it += satisfaction[loop_i];
        }
        return max_result;
    }
};