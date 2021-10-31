#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
  string frequencySort(string s) {
    const int s_len = s.size();
    std::map<char, int> res_map;
    std::set<std::pair<int, char>> res_set;
    for (int loop_i = 0; loop_i < s_len; ++loop_i) {
      res_map[s[loop_i]]++;
    }

    for (auto iter : res_map) {
      res_set.insert({iter.second, iter.first});
    }

    std::string result;
    for (auto iter = res_set.rbegin(); iter != res_set.rend(); ++iter) {
      for (int loop_i = 0; loop_i < iter->first; ++loop_i) {
        result += iter->second;
      }
    }

    return result;
  }
};