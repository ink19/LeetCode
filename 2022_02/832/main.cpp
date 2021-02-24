#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
    vector<vector<int>> result;
    std::transform(A.begin(), A.end(), std::back_inserter(result), [](vector<int> &item) {
      vector<int> result_item;
      std::transform(item.rbegin(), item.rend(), std::back_inserter(result_item), [](int data) {
        return !data;
      });
      return result_item;
    });
    return result;
  }
};