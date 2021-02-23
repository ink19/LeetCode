#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
  std::string convert_to_int(std::string s) {
    string result(s.size(), 0);
    for (int loop_i = 0; loop_i < s.length(); ++loop_i) {
      switch (s[loop_i]) {
        case 'a': case 'b': case 'c':
          result[loop_i] = '2';
        break;
        case 'd': case 'e': case 'f':
          result[loop_i] = '3';
        break;
        case 'g': case 'h': case 'i':
          result[loop_i] = '4';
        break;
        case 'j': case 'k': case 'l':
          result[loop_i] = '5';
        break;
        case 'm': case 'n': case 'o':
          result[loop_i] = '6';
        break;
        case 'p': case 'q': case 'r': case 's':
          result[loop_i] = '7';
        break;
        case 't': case 'u': case 'v':
          result[loop_i] = '8';
        break;
        case 'w': case 'x': case 'y': case 'z':
          result[loop_i] = '9';
        break;
      }
    }
    return result;
  };
  vector<string> getValidT9Words(string num, vector<string> &words) {
    return std::accumulate(words.begin(), words.end(), vector<string>(), [&num, this](vector<string> &result, string word) {
      if (convert_to_int(word) == num) {
        result.push_back(word);
      }
      return result;
    });
  }
};

int main() {
  vector<string> data = {"tree", "used"};
  Solution s;
  auto result = s.getValidT9Words("8733", data);
  for (int loop_i = 0; loop_i < result.size(); ++loop_i) {
    std::cout << result[loop_i] << std::endl;
  }
}