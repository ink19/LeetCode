#include <vector>
#include <stack>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int pow(int n) {
        int result = 1;
        for (int loop_i = 0; loop_i < n; ++loop_i) {
            result *= 2;
        }
        return result;
    }
    vector<int> pathInZigZagTree(int label) {
        int level = std::log(label)/std::log(2);
        vector<int> result(level + 1, 0);
        result[level] = label;
        while (level--) {
            label = label / 2;
            result[level] = pow(level + 1) - 1 - label + pow(level); 
            label = result[level];
        }
        return result;
    }
};
int main() {
}