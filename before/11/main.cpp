#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0) return 0;
        int begin = 0; int end = height.size() - 1;
        int max = 0;
        while (begin < end) {
            int temp_sq = (end - begin) * std::min(height[begin], height[end]);
            if (temp_sq > max) max = temp_sq;
            if (height[begin] > height[end]) {
                end--;
            } else {
                begin++;
            }
        }
        return max;
    }
};