#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int uniqueMorseRepresentations(vector<string> &words) {
    vector<string> mcode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    std::set<string> result_set;

    for (auto word : words) {
      string mcode_ = "";
      for (int loop_i = 0; loop_i < word.size(); ++loop_i) {
        mcode_ += mcode[word[loop_i] - 'a'];
      }
      result_set.insert(mcode_);
    }

    return result_set.size();
  }
};