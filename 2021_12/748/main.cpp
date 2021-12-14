#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  bool isword(char a) {
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) return true;
    return false;
  }
  string shortestCompletingWord(string licensePlate,const vector<string> &words) {
    std::string result = "111111aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    std::vector<int> licensePlateS(26, 0);
    for (int loop_i = 0; loop_i < licensePlate.size(); ++loop_i) {
      if (isword(licensePlate[loop_i])) {
        licensePlateS[std::tolower(licensePlate[loop_i]) - 'a']++;
      }
    }
    
    
    for (int loop_i = 0; loop_i < words.size(); ++loop_i) {
      std::vector<int> comp_word(26, 0);
      auto tw = words[loop_i];
      for (int loop_j = 0; loop_j < tw.size(); ++loop_j) {
        comp_word[tw[loop_j] - 'a']++;
      }
      bool is_ok = true;
      for (int loop_j = 0; loop_j < 26; ++loop_j) {
        if (comp_word[loop_j] < licensePlateS[loop_j]) {
          is_ok = false;
          break;
        }
      }
      if (is_ok) {
        if (result.size() > words[loop_i].size()) result = words[loop_i];
      }
    }

    return result;
  }
};

