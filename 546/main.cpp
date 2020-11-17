#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        if (boxes.size() == 0) return 0;
        std::vector<std::pair<int, int> > box_comp;
        int size_len = 1;
        int num = boxes[0];
        for (int loop_i = 1; loop_i < static_cast<int>(boxes.size()); ++loop_i) {
            if (num != boxes[loop_i]) {
                box_comp.push_back(std::make_pair(num, size_len));
                num = boxes[loop_i];
                size_len = 1;
            }
        }
        box_comp.push_back(std::make_pair(num, size_len));

        int Q[101][101];
        const int box_len = box_comp.size();
        for (int loop_i = 0; loop_i < box_len; ++loop_i) {
            for (int loop_j = 0; loop_j < box_len; ++loop_j) {
                Q[loop_i][loop_j] = 0;
            }
        }
        for (int loop_i = 0; loop_i < box_len; ++loop_i) {
            Q[loop_i][1] = box_comp[loop_i].second * box_comp[loop_i].second;
        }

        for (int loop_j = 2; loop_j < box_len; ++loop_j) {
            for (int loop_i = 0; loop_i < box_len - loop_j + 1; ++loop_i) {
                
            }
        }
    }
};

int main() {
    vector<int> data = {1,3,2,2,2,3,4,3,1};
    Solution s;
    std::cout << s.removeBoxes(data) << std::endl;
}