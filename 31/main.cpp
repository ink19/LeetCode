#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int swap_1 = 0;
        int swap_2 = 0;
        int loop_i = 0;
        for (loop_i = static_cast<int>(nums.size()) - 1; loop_i > 0; --loop_i) {
            if (nums[loop_i] > nums[loop_i - 1]) break; 
        }

        swap_1 = loop_i - 1;

        if (swap_1 == -1) {
            std::sort(nums.begin(), nums.end());
            return;
        }
        swap_2 = swap_1 + 1;
        for (loop_i = swap_1 + 1; loop_i < static_cast<int>(nums.size()); ++loop_i) {
            if (nums[loop_i] > nums[swap_1] && nums[loop_i] < nums[swap_2]) {
                swap_2 = loop_i;
            }
        }

        std::swap(nums[swap_2], nums[swap_1]);
        std::sort(nums.begin() + swap_1 + 1, nums.end());
    }
};