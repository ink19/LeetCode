#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int cur_1 = 0, cur_2 = 0;
        long long llk = k;
        const int nums_len = nums.size();
        if (nums_len <= 1) return nums_len;
 
        for (cur_1 = 1; cur_1 < nums_len; ++cur_1) {
            llk -= ((long long)(cur_1 - cur_2)) * ((long long)(nums[cur_1] - nums[cur_1 - 1]));
            while (llk < 0) {
                llk += (long long)nums[cur_1] - nums[cur_2];
                cur_2++;
            }
            
            if (cur_1 - cur_2 + 1 > result) {
                result = cur_1 - cur_2 + 1;
            }
        }

        return result;
    }
};

int main() {
    vector<int> data = {1,2,4};
    int k = 5;
    Solution s;
    std::cout << s.maxFrequency(data, k) << std::endl;
}