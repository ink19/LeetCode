#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int str_len = nums.size();
        for (int loop_i = 0; loop_i < str_len; ++loop_i) {
            if (nums[loop_i] > 0 && nums[loop_i] <= str_len) continue;
            nums[loop_i] = -1;
        }
        for (int loop_i = 0; loop_i < str_len; ++loop_i) {
            if (nums[loop_i] != -1 && nums[loop_i] != 0){
                int temp_data = nums[loop_i];
                do {
                    int temp2_data = nums[temp_data - 1];
                    nums[temp_data - 1] = 0;
                    temp_data = temp2_data;
                } while((temp_data != -1 && temp_data != 0) && (nums[temp_data - 1] != -1 || nums[temp_data - 1] != 0));
            }
        }

        for (int loop_i = 0; loop_i < str_len; ++loop_i) {
            if (nums[loop_i] != 0) return loop_i + 1;
        }
        return str_len + 1;
    }
};


int main() {
    Solution s;
    vector<int> data = {1,2,0};
    std::cout << s.firstMissingPositive(data) << std::endl;
    return 0;
}