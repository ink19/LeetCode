#include <vector>
#include <iostream>

using namespace std;

void print_vector(vector<int> &data) {
  for (auto item : data) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

class Solution {
public:
  bool verifyPostorder(vector<int> &postorder) {
    const int postorder_len = postorder.size();
    if (postorder_len <= 1) return true;
    int left_index = 0;
    for (int loop_i = 0; loop_i < postorder_len; ++loop_i) {
      if (postorder[loop_i] >= postorder[postorder_len - 1]) {
        left_index = loop_i - 1;
        break;
      }
    }
    for (int loop_i = left_index + 1; loop_i < postorder_len - 1; ++loop_i) {
      if (postorder[loop_i] < postorder[postorder_len - 1]) {
        return false;
      }
    }
    vector<int> left_postorder(postorder.begin(), postorder.begin() + left_index + 1);
    if (!verifyPostorder(left_postorder)) {
      return false;
    }
    vector<int> right_postorder(postorder.begin() + left_index + 1, postorder.end() - 1);
    if (!verifyPostorder(right_postorder)) return false;
    return true;
  }
};

int main() {
  vector<int> data = {1, 2, 3, 4, 5};
  Solution s;
  std::cout << s.verifyPostorder(data) << std::endl;
}