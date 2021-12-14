#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> result;
    for (int loop_i = 1; loop_i <= n; ++loop_i) {
      std::string temp_string;
      if (loop_i % 3 == 0) temp_string += "Fizz";
      if (loop_i % 5 == 0) temp_string += "Buzz";
      if (!temp_string.size()) temp_string = std::to_string(loop_i);
      result.push_back(temp_string);
    }
    return result;
  }
};