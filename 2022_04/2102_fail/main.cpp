#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <list>

using namespace std;

class SORTracker {
  std::list<std::pair<int, std::string>> test;
  std::vector<std::pair<int, std::string>> data; 
  int request = 0;
public:
  SORTracker() {
  
  }

  void add(string name, int score) {
    data.push_back({
      score, name
    });
    std::sort(data.begin(), data.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b){
      if (a.first == b.first) return a.second < b.second;
      return a.first > b.first;
    });
  }

  string get() {
    return data[request++].second;
  }
};
