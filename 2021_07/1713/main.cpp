#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxLenGreater(vector<int>& arr, int len) {
        if (len == 0) return 0;
        int result = 0;
        std::vector<int> tails;
        tails.push_back(arr[0]);
        for (int loop_i = 1; loop_i < len; ++loop_i) {
            if (arr[loop_i] > tails.back()) {
                tails.push_back(arr[loop_i]);
            } else {
                auto rt_iter = std::upper_bound(tails.begin(), tails.end(), arr[loop_i]);
                if (rt_iter == tails.end()) continue;
                if (rt_iter != tails.begin() && *(rt_iter - 1) >= arr[loop_i]) continue;
                *rt_iter = arr[loop_i];
            }
        }
        result = tails.size();
        return result;
    }
    int minOperations(vector<int>& target, vector<int>& arr) {
        std::map<int, int> target_map;
        const int target_len = target.size();
        const int arr_len = arr.size();
        for (int loop_i = 0; loop_i < target_len; ++loop_i) {
            target_map[target[loop_i]] = loop_i;
        }
        int arr_new_len = 0;
        for (int loop_i = 0; loop_i < arr_len; ++loop_i) {
            if (target_map.count(arr[loop_i]) != 0) {
                arr[arr_new_len] = target_map[arr[loop_i]];
                arr_new_len++;
            }
        }
        if (arr_new_len == 0) return target_len;
        
        return target_len - maxLenGreater(arr, arr_new_len);
    }
};

int main() {
    vector<int> data1 = {995168292,13690313,293160801,642482000,810529261,98173438,456394738,882168981,961299834,794671198};
    vector<int> data2 =  {13690313,794671198,957156640,882168981,882168981,293160801,794671198,111281680,293160801,642482000};
    Solution s;
    std::cout << s.minOperations(data1, data2) << std::endl;
}