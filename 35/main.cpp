#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        int mid = (begin + end) >> 1;
        int result = end + 1;
        while (begin <= end) {
            mid = (begin + end) >> 1;
            if (nums[mid] > target) {
                result = mid;
                end = mid - 1;
            } else if (nums[mid] < target) {
                
                begin = mid + 1;
            } else {
                result = mid;
                break;
            }
        }
        return result;
    }
};

