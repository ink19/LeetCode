#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
      return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    
    for (int loop_i = 0; loop_i < static_cast<int>(people.size()); ++loop_i) {
      people.at(loop_i).push_back(loop_i);
    }
    sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
      return (a[1] + a[2]) < (b[1] + b[2]);
    });
    return people;
  }
};

int main() {
  Solution s;
  std::vector<std::vector<int>> data = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
  auto result = s.reconstructQueue(data);
  for (auto data : result) {
    std::cout << "[";
    for (auto idata : data) {
      std::cout << idata << ",";
    }
    std::cout << "],";
  }
  std::cout << std::endl;
  return 0;
}