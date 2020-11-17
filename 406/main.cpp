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
    vector<vector<int>> result(people.size(), vector<int>());
    int loop_index = 0;
    for (int loop_i = 0; loop_i < static_cast<int>(people.size()); ++loop_i) {
      int insert_index = loop_index;
      int space_index = people.at(loop_i)[1];
      while (result[insert_index].size() != 0) insert_index++;
      while (space_index != 0) {
        
        insert_index++;
        space_index--;
        while (result[insert_index].size() != 0) insert_index++;
      }
      result[insert_index] = people[loop_i];
    }
    return result;
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