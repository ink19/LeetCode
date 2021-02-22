#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    int max_len = R + C;
    vector<vector<int>> result;
    auto verify_RC = [&R, &C](int r, int c) {
      return (c >= 0 && c < C && r >= 0 && r < R);
    };
    for (int loop_i = 0; loop_i < max_len; ++loop_i) {
      for (int dis_r = 0; dis_r <= loop_i; ++dis_r) {
        int dis_c = loop_i - dis_r;
        int index_r = r0 + dis_r;
        int index_c = c0 + dis_c;
        if (verify_RC(index_r, index_c)) {
          result.push_back({index_r, index_c});
        }

        if (dis_r != 0) {
          index_r = r0 - dis_r;
          index_c = c0 + dis_c;
          if (verify_RC(index_r, index_c)) {
            result.push_back({index_r, index_c});
          }
        }

        if (dis_c != 0) {
          index_r = r0 + dis_r;
          index_c = c0 - dis_c;
          if (verify_RC(index_r, index_c)) {
            result.push_back({index_r, index_c});
          }
        }

        if (dis_c != 0 && dis_r != 0) {
          index_r = r0 - dis_r;
          index_c = c0 - dis_c;
          if (verify_RC(index_r, index_c)) {
            result.push_back({index_r, index_c});
          }
        }
      }
    }
    return result;
  }
};


int main() {
  Solution s;
  auto result = s.allCellsDistOrder(2, 2, 0, 1);
  for (auto item : result) {
    std::cout << "[";
    for (auto iitem : item) {
      std::cout << iitem << ",";
    }
    std::cout << "],";
  }
  std::cout << std::endl;
  return 0;
}