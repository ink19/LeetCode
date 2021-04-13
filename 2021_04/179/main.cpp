#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    auto nums_number = std::accumulate(nums.begin(), nums.end(), std::vector<std::string>(), [](std::vector<std::string> data, int idata) {
      data.push_back(std::to_string(idata));
      return data;
    });
    std::sort(nums_number.begin(), nums_number.end(), [](const std::string &a, const std::string &b){
      return a + b > b + a;
    });
    auto temp_result = std::accumulate(nums_number.begin(), nums_number.end(), std::string(), [](std::string result, std::string input_s) {
      return result + input_s;
    });
    if (temp_result[0] == '0') {
      return "0";
    } 
    return temp_result;
  }
};