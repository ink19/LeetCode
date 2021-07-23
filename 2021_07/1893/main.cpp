#include <ostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        int tleft = left, tright = left - 1;
        for (auto mrange : ranges) {
            if (mrange[0] > tright + 1) return false;

            if (tleft > mrange[0]) {
                tleft = mrange[0];
            }
            if (tright < mrange[1]) {
                tright = mrange[1];
            }
        }
        if (tleft <= left && tright >= right) return true;
        return false;
    }
};


int main() {
    vector<vector<int>> data = {{1,2},{3,4},{5,6}};
    Solution s;
    std::cout << s.isCovered(data, 2, 5) << std::endl;
}