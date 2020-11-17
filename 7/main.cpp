#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long lx = x;
        if (lx < 0) lx = -lx;
        string sx = std::to_string(lx);
        std::reverse(sx.begin(), sx.end());
        lx = std::stoll(sx);
        if (x < 0) lx = -lx;
        if (lx < -(((long long)1) << 31) || lx > (((long long)1) << 31) - 1) return 0;
        return lx;
    }
};

int main() {
    Solution s;
    cout << s.reverse(1463847412) << endl;
}