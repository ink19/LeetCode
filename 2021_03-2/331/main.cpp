#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  std::vector<std::string> split(const std::string &input, const char sp_c) {
    std::vector<std::string> result;
    auto ob_iter = input.begin();
    for (auto oe_iter = input.begin(); oe_iter != input.end(); ++oe_iter) {
      if (*oe_iter == sp_c) {
        result.push_back(std::string(ob_iter, oe_iter));
        ob_iter = oe_iter + 1;
      }
    } 
    result.push_back(std::string(ob_iter, input.end()));
    return result;
  }
  bool isValidSerialization(string preorder) {
    auto split_str = split(preorder, ',');
    int begin_index = 0;
    int end_index = 1;
    while (begin_index != end_index) {
      if (end_index > split_str.size()) {
        return false;
      }
      int this_none_shape = 0;
      for (int loop_i = begin_index; loop_i < end_index; ++loop_i) {
        if (split_str[loop_i] != "#") {
          this_none_shape++;
        }
      }
      begin_index = end_index;
      end_index += this_none_shape * 2;
    }
    if (end_index == split_str.size()) return true;
    else return false;
  }
};

int main() {
  Solution s;
  std::cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << std::endl;
  return 0;
}
