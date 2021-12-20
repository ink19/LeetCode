#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPal(std::string::iterator begin, std::string::iterator end) {
    while (begin < end) {
      if (*begin != *(end - 1)) {
        return false;
      }
    }
    return true;
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    return result;
  }
};