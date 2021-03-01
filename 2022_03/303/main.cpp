#include <cmath>
#include <iostream>
#include <memory>
#include <vector>
#include <queue>

using namespace std;

struct num_tree_node {
  int sum;
  int left;
  int right;
  std::shared_ptr<num_tree_node> left_node;
  std::shared_ptr<num_tree_node> right_node;
  num_tree_node(int sum, int left, int right,
                std::shared_ptr<num_tree_node> left_node,
                std::shared_ptr<num_tree_node> right_node)
      : sum(sum), left(left), right(right), left_node(left_node),
        right_node(right_node) {}
};

typedef std::shared_ptr<num_tree_node> num_tree_node_ptr;

class NumArray {
public:
  NumArray(vector<int> &nums) : nums(nums) {
    std::queue<num_tree_node_ptr> queue[2];
    const int nums_len = nums.size();
    if (nums_len == 0) {
      num_tree = std::make_shared<num_tree_node>(0, 0, 0, nullptr, nullptr);
      return;
    }
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      queue[0].push(std::make_shared<num_tree_node>(nums[loop_i], loop_i, loop_i, nullptr, nullptr));
    }
    int swither = 0;
    while (queue[swither].size() > 1) {
      while (!queue[swither].empty()) {
        if (queue[swither].size() == 1) {
          queue[!swither].push(queue[swither].front());
          queue[swither].pop();
        } else {
          auto left_node = queue[swither].front();
          queue[swither].pop();
          auto right_node = queue[swither].front();
          queue[swither].pop();
          auto node = std::make_shared<num_tree_node>(left_node->sum + right_node->sum, left_node->left, right_node->right, left_node, right_node);
          queue[!swither].push(node);
        }
      }
      swither =  !swither;
    }
    num_tree = queue[swither].front();
  }

  int sumRange(int i, int j, num_tree_node_ptr tree) {
    if (i <= tree->left && j >= tree->right) return tree->sum;
    int result = 0;
    if (i <= tree->left_node->right) {
      result += sumRange(i, j, tree->left_node);
    }
    if (j >= tree->right_node->left) {
      result += sumRange(i, j, tree->right_node);
    }
    return result;
  }

  int sumRange(int i, int j) {
    return sumRange(i, j, num_tree);
  }

  vector<int> &nums;
  num_tree_node_ptr num_tree;
};