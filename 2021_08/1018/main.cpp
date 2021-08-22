#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int temp_data = 0;
        int nums_len = nums.size();
        for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
            temp_data <<= 1;
            temp_data %= 5;
            temp_data += nums[loop_i];
            if (temp_data % 5 == 0) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};