#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  int result = 0;
  typedef vector<string>::iterator iter_type;

  int delete_iter(iter_type iter_begin, iter_type iter_end, int now_index) {
    game_begin:
    if (now_index >= (*iter_begin).size()) return 0;
    auto last_iter = iter_begin;
    auto pre_iter = iter_begin;
    for (auto loop_iter = iter_begin; loop_iter != iter_end; ++loop_iter) {
      if ((*last_iter).substr(0, now_index) != (*loop_iter).substr(0, now_index)) {
        last_iter = loop_iter;
      } else {
        if ((*pre_iter)[now_index] > (*loop_iter)[now_index]) {
          result++;
          
          for (auto loop_iter_i = iter_begin; loop_iter_i != iter_end; ++loop_iter_i) {
            (*loop_iter_i).erase(now_index, 1);
          }
          goto game_begin;
        }
      }
      pre_iter = loop_iter;
    }
    delete_iter(iter_begin, iter_end, now_index + 1);
    return 0;
  }
  
  int minDeletionSize(vector<string> &strs) {
    delete_iter(strs.begin(), strs.end(), 0);
    return result;  
  }
};

int main() {
  vector<string> data = {"vdy","vei","zvc","zld"};
  std::cout << Solution().minDeletionSize(data) << std::endl;
}