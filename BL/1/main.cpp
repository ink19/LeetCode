#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;
class Solution {
public:
    /* Write Code Here */
    int strstr(string a, string b) {
        const int a_len = a.size();
        const int b_len = b.size();
        for (int loop_i = 0; loop_i < a_len; ++loop_i) {
            bool is_ok = true;
            if (loop_i + b_len > a_len) return -1;
            for (int loop_j = 0; loop_j < b_len; ++loop_j) {
                if (a[loop_i + loop_j] != b[loop_j]) {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok) {
                return loop_i;
            }
        }
        return -1;
    }
};

int main() {
    int res;

    string _a;
    getline(cin, _a);
    string _b;
    getline(cin, _b);
    Solution *s = new Solution();
    res = s->strstr(_a, _b);
    cout << res << endl;
    
    return 0;

}
