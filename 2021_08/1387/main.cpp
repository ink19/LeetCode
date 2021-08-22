#include <map>
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::map<int, int> cache;
    int getF(int data) {
        if (data == 1) return 0;
        auto find_it = cache.find(data);
        if (find_it != cache.end()) {
            return find_it->second;
        }

        int time = 0;
        if (data % 2) {
            time = getF(data * 3 + 1);
        } else {
            time = getF(data / 2);
        }
        time++;
        cache[data] = time;
        return time;
    }
    int getKth(int lo, int hi, int k) {
        std::vector<int> data(hi - lo + 1, 0);
        for (int loop_i = lo; loop_i <= hi; ++loop_i) {
            data[loop_i - lo] = loop_i;
            getF(loop_i);
        }
        std::sort(data.begin(), data.end(), [this](int a, int b) {
            if (cache[a] == cache[b]) {
                return a < b;
            } else {
                return cache[a] < cache[b];
            }
        });
        return data[k - 1];
    }
};