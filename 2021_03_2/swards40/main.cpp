#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    std::sort(arr.begin(), arr.end());
    return vector<int> (arr.begin(), arr.begin() + k);
  }
};