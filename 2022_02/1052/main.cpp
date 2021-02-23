#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
    int begin = 0;
    int more_customer = 0;
    int sum_customer = 0;
    int max_more = 0;
    const int customers_len = customers.size();
    for (int loop_i = 0; loop_i < customers_len; ++loop_i) {
      if (grumpy [loop_i] == 0) {
        sum_customer += customers[loop_i];
      } else {
        more_customer += customers[loop_i];
      }
      if (loop_i - begin + 1 > X) {
        if (grumpy[begin] == 1) {
          more_customer -= customers[begin];
        }
        begin++;
      } 
      if (more_customer > max_more) max_more = more_customer;
    }
    return max_more + sum_customer;
  }
};