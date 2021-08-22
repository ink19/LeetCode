#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        std::map<int, int> dir_map;
        const int array_len = array.size();
        int sum = 0;
        int result_left = 0;
        int result_right = 0;
        dir_map[0] = -1;
        for (int loop_i = 0; loop_i < array_len; ++loop_i) {
            if (array[loop_i][0] >= '0' && array[loop_i][0] <= '9') {
                sum++;
            } else {
                sum--;
            }
            auto find_it = dir_map.find(sum);
            if (find_it == dir_map.end()) {
                dir_map[sum] = loop_i;
            } else {
                if (result_right - result_left < loop_i - find_it->second) {
                    result_right = loop_i;
                    result_left = find_it->second;
                }
            }
        }
        return vector<string>(array.begin() + result_left + 1, array.begin() + result_right + 1);
    }
};