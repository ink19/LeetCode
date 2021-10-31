#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
  std::pair<string, string> word_to_key(const string &word) {
    string key1 = word;
    string key2 = word;
    for (int loop_i = 0; loop_i < word.size(); ++loop_i) {
      key1[loop_i] = std::tolower(key1[loop_i]);
      key2[loop_i] = std::tolower(key2[loop_i]);
      if (key1[loop_i] == 'a' || key1[loop_i] == 'e' || key1[loop_i] == 'i' || key1[loop_i] == 'o' || key1[loop_i] == 'u') {
        key1[loop_i] = '.';
      }
    }
    return {key2, key1};
  }
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    std::map<string, std::pair<string, std::set<string>>> word_map;
    for (auto iter = wordlist.rbegin(); iter != wordlist.rend(); ++iter) {
      auto key = word_to_key(*iter);
      auto temp_data = word_map[key.first].second;
      temp_data.insert(*iter);
      word_map[key.first] = {*iter, temp_data};

      temp_data = word_map[key.second].second;
      temp_data.insert(*iter);
      word_map[key.second] = {*iter, temp_data};
    }
    std::vector<string> result;
    for (auto query : queries) {
      auto key = word_to_key(query);
      auto temp_data = word_map[key.first];
      if (temp_data.second.find(query) == temp_data.second.end()) {
        if (temp_data.first == "") {
          auto temp_data = word_map[key.second];
          result.push_back(temp_data.first);
        } else {
          result.push_back(temp_data.first);
        }
      } else {
        result.push_back(query);
      }
    }
    return result;
  }
};