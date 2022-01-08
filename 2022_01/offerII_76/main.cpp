#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  typedef vector<int>::iterator iter_type;
  int findKthLargest(iter_type begin_iter, iter_type end_iter, int find_k) {
    auto iter_right = begin_iter + 1;
    auto iter_left = end_iter - 1;
    while (iter_right <= iter_left) {
      if ((*iter_right) < (*begin_iter)) {
        std::iter_swap(iter_right, iter_left);
        iter_left--;
      } else {
        iter_right++;
      }
    }
    std::iter_swap(iter_left, begin_iter);
    int split_mid = iter_left - begin_iter;
    if (split_mid == find_k) return *iter_left;
    if (split_mid > find_k) return findKthLargest(begin_iter, iter_left, find_k);
    return findKthLargest(iter_left + 1, end_iter, find_k - split_mid - 1);
  }
  int findKthLargest(vector<int> &nums, int k) {
    return findKthLargest(nums.begin(), nums.end(), k - 1);
  }
};

int main() {
  vector<int> data= {3, 2, 1, 5, 6, 4};
  std::cout << Solution().findKthLargest(data, 2) << std::endl;
}