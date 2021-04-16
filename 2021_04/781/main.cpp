#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
  int numRabbits(vector<int> &answers) {
    const int answers_len = answers.size();
    std::map<int, std::tuple<int, int>> data;
    for (int loop_i = 0; loop_i < answers_len; ++loop_i) {
      if (data.count(answers[loop_i])) {
        auto idata = data[answers[loop_i]];
        idata = {std::get<0>(idata), std::get<1>(idata) + 1};
        if (std::get<1>(idata) > answers[loop_i] + 1) {
          idata = {std::get<0>(idata) + 1, 1};
        }
        data[answers[loop_i]] = idata;
      } else {
        data[answers[loop_i]] = {1, 1};
      }
    }
    int sum = 0;
    for (auto loop_item : data) {
      sum += (loop_item.first + 1) * std::get<0>(loop_item.second);
    }
    return sum;
  }
};