#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    
    // int find_it(vector<int> &num, int target) {
    //     auto find = std::lower_bound(num.begin(), num.begin(), target);
    //     if (find == num.end() || *find != target) return -1;
    //     return find - num.begin();
    // }
    set<string> keys;
    int search(vector<int>::iterator begin, vector<int>::iterator end, int target, vector<int> now_vector, string key) {
        if (begin == end) return 0;
        if (target <= 0) return 0;

        auto find_target = std::lower_bound(begin, end, target);
        
        if (find_target != end && *find_target == target) {
            vector<int> fork_vector = now_vector;
            fork_vector.push_back(target);

            auto fork_key = key;
            fork_key += std::to_string(target);
            if (keys.find(fork_key) == keys.end()) {
                result.push_back(fork_vector);
                keys.insert(fork_key);
            }
            
        }

        if (find_target == begin) {
            return 0;
        }

        for (auto loop_begin = begin; loop_begin != find_target; ++loop_begin) {
            if (loop_begin != begin) {
                vector<int>::iterator fork_iter = loop_begin;
                fork_iter--;
                if (*loop_begin == *fork_iter) continue;
            } 
            vector<int> fork_vector = now_vector;
            fork_vector.push_back(*loop_begin);
            vector<int>::iterator fork_iter = loop_begin;
            fork_iter++;
            auto fork_key = key;
            fork_key += std::to_string(*loop_begin);
            search(fork_iter, find_target, target - *loop_begin, fork_vector, fork_key);
        }
        return 0;
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        const int num_len = num.size();
        search(num.begin(), num.end(), target, {}, "");
        return result;
    }
};

int main() {
    vector<int> data = {100,10,20,70,60,10,50};
    sort(data.begin(), data.end());
    auto result = Solution().combinationSum2(data, 80);
    for (int loop_i = 0; loop_i < result.size(); ++loop_i) {
        for (int loop_j = 0; loop_j < result[loop_i].size(); ++loop_j) {
            std::cout << result[loop_i][loop_j] << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}