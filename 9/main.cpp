#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long temp_x = x;
        long long rx = 0;
        while (temp_x != 0) {
            rx *= 10;
            rx += temp_x % 10;
            temp_x /= 10;
        }
        if (rx == x) return true;
        else return false;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(123) << endl;
}