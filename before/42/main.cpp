#include <iostream>
#include <vector>
#include <string>

using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> save_length(height.size(), 0);
        int max_length = 0;
        for (int loop_i = 0; loop_i < static_cast<int>(height.size()); ++loop_i) {
            if (height[loop_i] > max_length) {
                max_length = height[loop_i];
            }
            save_length[loop_i] = max_length;
        }
        max_length = 0;
        for (int loop_i = static_cast<int>(height.size()) - 1; loop_i >= 0; --loop_i) {
            if (height[loop_i] > max_length) {
                max_length = height[loop_i];
            }
            if (max_length < save_length[loop_i]) {
                save_length[loop_i] = max_length;
            }
        }

        int result = 0;
        for (int loop_i = 0; loop_i < static_cast<int>(height.size()); ++loop_i) {
            result += save_length[loop_i] - height[loop_i];
        }
        return result;
    }
};