#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int str_num = strs.size();
        if (str_num == 0) return "";
        int max_len = 0;
        int str_len = strs.at(0).size();
        for (int loop_i = 0; loop_i < str_len; ++loop_i) {
            for (int loop_j = 0; loop_j < str_num; ++loop_j) {
                if (strs[loop_j].size() <= loop_i || strs[loop_j][loop_i] != strs[0][loop_i]) {
                    return strs.at(0).substr(0, max_len);
                }
            }
            max_len++;
        }
        return strs.at(0);
    }
};
