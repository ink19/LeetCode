#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;

class Solution {
    std::map<int, int> freq_to_int;
    std::map<int, int> int_to_freq_iter;    
public:

    int maxEqualFreq(vector<int>& nums) {
        const int nums_len = nums.size();
        int result = 0;
        for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
            auto num_iter = int_to_freq_iter.find(nums[loop_i]);
            if (num_iter == int_to_freq_iter.end()) {
                freq_to_int[1]++;
                int_to_freq_iter[nums[loop_i]] = 1;
            } else {
                int freq = num_iter->second;
                freq_to_int[freq]--;
                if (freq_to_int[freq] == 0) {
                    freq_to_int.erase(freq);
                }
                freq_to_int[freq + 1]++;
                int_to_freq_iter[nums[loop_i]]++;
            }
            if (freq_to_int.size() <= 2) {
                if (freq_to_int.size() == 1) {
                    if (freq_to_int.begin()->second == 1 || freq_to_int.begin()->first == 1) if (loop_i > result) result = loop_i;
                } else {
                    auto one_iter = freq_to_int.begin();
                    auto two_iter = one_iter++;
                    if (one_iter->second != 1 && two_iter->second != 1) {
                        continue;
                    }

                    if (two_iter->second == 1) {
                        if (two_iter->first == 1 || two_iter->first - one_iter->first == 1) {
                            if (loop_i > result) result = loop_i;
                        }
                    }
                    
                    if (one_iter->second == 1) {
                        if (one_iter->first == 1 || one_iter->first - two_iter->first == 1) {
                            if (loop_i > result) result = loop_i;
                        }
                    }
                }
            } 
        }
        return result + 1;
    }
};

int main() {
    std::vector<int> data = {1,1,1,2,2,2};
    std::cout << Solution().maxEqualFreq(data) << std::endl;
}