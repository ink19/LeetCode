#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    /* Write Code Here */
    string reorder(string a, string b) {
        std::map<char, int> data;
        const int a_len = a.size();
        const int b_len = b.size();
        for (int loop_i = 0; loop_i < a.size(); ++loop_i) {
            data[a[loop_i]] = 10000;
        }
        for (int loop_i = 0; loop_i < b.size(); ++loop_i) {
            data[b[loop_i]] = loop_i;
        }

        std::sort(a.begin(), a.end(), [&](const char &ai, const char aj) {
            return data[ai] < data[aj];
        });
        return a;
    }
};
int main() {
    string res;

    string _a;
    getline(cin, _a);
    string _b;
    getline(cin, _b);
    Solution *s = new Solution();
    res = s->reorder(_a, _b);
    cout << res << endl;
    
    return 0;

}
