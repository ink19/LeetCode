#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int nums_len = nums.size();
        int now_num = 0;
        int now = 0;
        for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
            if (now_num == 0) {
                now = nums[loop_i];
                now_num = 1;
            } else {
                if (now == nums[loop_i]){
                    now_num++;
                } else {
                    now_num--;
                }
            }
        }
        return now;
    }
};