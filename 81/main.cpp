#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int get_swap_point(vector<int>& nums) {
        int begin = 0;
        int end = nums.size();
        int mid = 0;
        while (begin <= end) {
            mid = (begin + end) >> 1;
            if (nums[mid] <= nums[begin]) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return end;
    }

    bool search(vector<int>& nums, int target) {
        int swap_point = 0;
        return true;
    }
};

int main() {
    Solution s;
    vector<int> data = {2,5,6,0,0,1,2};
    std::cout << s.get_swap_point(data) << std::endl;
}