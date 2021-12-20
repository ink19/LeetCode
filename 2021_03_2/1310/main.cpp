#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    const int arr_len = arr.size();
    int tresult = 0;
    for (int loop_i = 0; loop_i < arr_len; ++loop_i) {
      tresult ^= arr[loop_i];
      arr[loop_i] = tresult;
    }
    vector<int> result;
    for (int loop_i = 0; loop_i < queries.size(); ++loop_i) {
      int iresult = 0;
      if (queries[loop_i][0] == 0) {
        iresult = arr[queries[loop_i][1]];
      } else {
        iresult = arr[queries[loop_i][0] - 1] ^ arr[queries[loop_i][1]];
      }
      result.push_back(iresult);
    }
    return result;
  }
};