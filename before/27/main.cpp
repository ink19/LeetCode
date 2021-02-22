#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const int nums_len = nums.size();
        int new_len = 0;
        for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
            if (nums[loop_i] != val) {
                nums[new_len] = nums[loop_i];
                new_len++;
            } 
        }
        return new_len;
    }
};


int main() {

}