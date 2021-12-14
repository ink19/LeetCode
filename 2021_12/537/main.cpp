#include <string>
#include <cstdio>
using namespace std;

class Solution {
public:
  string complexNumberMultiply(string num1, string num2) {
    int i1 = 0, i2 = 0;
    int j1 = 0, j2 = 0;
    int result_i = 0;
    int result_j = 0;
    std::sscanf(num1.c_str(), "%d+%di", &i1, &j1);
    std::sscanf(num2.c_str(), "%d+%di", &i2, &j2);

    result_i = i1 * i2 - j1 * j2;
    result_j = i1 * j2 + i2 * j1;
    string result;
    result += std::to_string(result_i);
    result += "+";
    result += std::to_string(result_j);
    result += "i";
    return result;
  }
};