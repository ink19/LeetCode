#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkIfPangram(string sentence) {
    std::vector<int> data(26, 0);
    for (int loop_i = 0; loop_i < sentence.size(); ++loop_i) {
      data[sentence[loop_i] - 'a'] += 1;
    }

    for (int loop_i = 0; loop_i < 26; ++loop_i) {
      if (data[loop_i] == 0) return false;
    }
    return true;
  }
};