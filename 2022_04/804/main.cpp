#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  const std::vector<std::string> mrcode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
  int uniqueMorseRepresentations(vector<string> &words) {
    std::set<std::string> trans;
    for (const auto& word : words) {
      std::string tran;
      for (const auto& dig : word) {
        tran += mrcode[dig - 'a'];
      }
      trans.insert(tran);
    }
    return trans.size();
  }
};
