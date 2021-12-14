#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    std::sort(courses.begin(), courses.end(), [](const std::vector<int>& a, const std::vector<int>& b){
      return a[1] < b[1];
    });
    const int courses_len = courses.size();
    std::priority_queue<int> pri_queue;
    int sum_queue = 0;
    for (int loop_i = 0; loop_i < courses_len; ++loop_i) {
      if (sum_queue + courses[loop_i][0] <= courses[loop_i][1]) {
        pri_queue.push(courses[loop_i][0]);
        sum_queue += courses[loop_i][0];
      } else {
        if (pri_queue.empty()) continue;
        if (pri_queue.top() > courses[loop_i][0] && sum_queue - pri_queue.top() + courses[loop_i][0] <= courses[loop_i][1]) {
          sum_queue = sum_queue - pri_queue.top() + courses[loop_i][0];
          pri_queue.pop();
          pri_queue.push(courses[loop_i][0]);
        }
      }
    }
    return pri_queue.size();
  }
};

int main() {
  std::vector<std::vector<int>> data = {{7,17},{3,12},{10,20},{9,10},{5,20},{10,19},{4,18}};
  std::cout << Solution().scheduleCourse(data) << std::endl;
}