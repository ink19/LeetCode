#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    vector<int> index_arr2(1001, 2000000);
    int arr1_len = arr1.size();
    int arr2_len = arr2.size();
    for (int loop_i = 0; loop_i < arr2_len; ++loop_i) {
      index_arr2[arr2[loop_i]] = loop_i * 1001;
    }

    std::sort(arr1.begin(), arr1.end(), [&index_arr2](const int &a, const int &b) {
      int temp_a = index_arr2[a] + a;
      int temp_b = index_arr2[b] + b;
      return temp_a < temp_b;
    });
    return arr1;
  }
};
