#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = m & n;
        int temp = n - m;
        int len = 0;
        while (temp >= (1 << len)) len++;
        len -= 1;
        if (len < 0) return result;
        else {
            result &= ((-1 << len) & std::numeric_limits<int>::max());
        }
        return result;
    }
};

int main() {
    Solution s;
    std::cout << s.rangeBitwiseAnd(0, 1) << std::endl;
}