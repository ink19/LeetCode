#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp_nums;
        for (int loop_i = 0, loop_j = 0; loop_i < nums1.size() || loop_j < nums2.size();) {
            if (loop_i == nums1.size()) {
                temp_nums.push_back(nums2.at(loop_j));
                loop_j++;
                continue;
            }
            if (loop_j == nums2.size())  {
                temp_nums.push_back(nums1.at(loop_i));
                loop_i++;
                continue;
            }
            if (nums1.at(loop_i) < nums2.at(loop_j)) {
                temp_nums.push_back(nums1.at(loop_i));
                loop_i++;
            } else {
                temp_nums.push_back(nums2.at(loop_j));
                loop_j++;
            }
        }

        if (temp_nums.size()%2 == 1)  {
            return temp_nums.at(temp_nums.size()/2);
        } else {
            return static_cast<double>(temp_nums.at(temp_nums.size()/2) + temp_nums.at(temp_nums.size()/2 - 1))/2.0;
        }
    }
};


int main() {
    Solution s;
    vector<int> n1 = {1, 3, 4};
    vector<int> n2 = {2};
    std::cout << s.findMedianSortedArrays(n1, n2);
}