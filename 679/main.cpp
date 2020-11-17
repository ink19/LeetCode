#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool judgePoint(vector<double> nums) {
        if (nums.size() == 1) {
            if (std::abs(nums[0] - 24) < 1e-6) {
                return true;
            } else {
                return false;
            }
        } 
        for (int loop_i = 0; loop_i < nums.size(); ++loop_i) {
            for (int loop_j = 0; loop_j < nums.size(); ++loop_j) {
                if (loop_i == loop_j) continue;
                vector<double> copy_data;
                for (int loop_s = 0; loop_s < nums.size(); ++loop_s) {
                    if (loop_s != loop_i && loop_s != loop_j) copy_data.push_back(nums[loop_s]);
                }
                copy_data.push_back(nums[loop_i] + nums[loop_j]);
                if (judgePoint(copy_data)) return true;
                copy_data.clear();
                for (int loop_s = 0; loop_s < nums.size(); ++loop_s) {
                    if (loop_s != loop_i && loop_s != loop_j) copy_data.push_back(nums[loop_s]);
                }
                copy_data.push_back(nums[loop_i] - nums[loop_j]);
                if (judgePoint(copy_data)) return true;
                copy_data.clear();
                for (int loop_s = 0; loop_s < nums.size(); ++loop_s) {
                    if (loop_s != loop_i && loop_s != loop_j) copy_data.push_back(nums[loop_s]);
                }
                copy_data.push_back(nums[loop_i] * nums[loop_j]);
                if (judgePoint(copy_data)) return true;
                copy_data.clear();
                for (int loop_s = 0; loop_s < nums.size(); ++loop_s) {
                    if (loop_s != loop_i && loop_s != loop_j) copy_data.push_back(nums[loop_s]);
                }
                if (nums[loop_j] == 0) continue;
                copy_data.push_back(nums[loop_i] / nums[loop_j]);
                if (judgePoint(copy_data)) return true;
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& nums) {
        vector<double> data;
        for (int loop_i = 0; loop_i < nums.size(); ++loop_i) {
            data.push_back(nums[loop_i]);
        }
        return judgePoint(data);
    }
};

int main() {
    Solution s;
    vector<int> data = {1, 2, 1, 2};
    std::cout << s.judgePoint24(data) << std::endl;
}