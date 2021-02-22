#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            return sqrt(a[0] * a[0] + a[1] * a[1]) > sqrt(b[0] * b[0] + b[1] * b[1]);
        });
        points.resize(K);
        return points;
    }
};


int main() {
    Solution s;
    
    return 0;
}