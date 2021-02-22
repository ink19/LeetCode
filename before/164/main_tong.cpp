#include <vector>

using std::vector;

struct bucket {
  int max;
  int min;
};

class Solution {
public:
  int maximumGap(vector<int> &nums) {
    const int nums_len = nums.size();
    if (nums_len <= 1) return 0;
    int nums_max = nums[0];
    int nums_min = nums[0];
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      if (nums[loop_i] > nums_max) {
        nums_max = nums[loop_i];
      }
      if (nums[loop_i] < nums_min) {
        nums_min = nums[loop_i];
      }
    }

    if (nums_max - nums_min == 0) return 0;

    int bucket_len = (nums_max - nums_min)/(nums.size() - 1);
    if (bucket_len == 0) bucket_len = 1;
    int bucket_num = (nums_max - nums_min)/(bucket_len) + 1;
    
    bucket *buckets = new bucket[bucket_num];

    for (int loop_i = 0; loop_i < bucket_num; ++loop_i){
      buckets[loop_i].max = -1;
      buckets[loop_i].min = -1;      
    }

    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      int bucket_index = (nums[loop_i] - nums_min)/bucket_len;
      if (buckets[bucket_index].max == -1 || buckets[bucket_index].max < nums[loop_i]) {
        buckets[bucket_index].max = nums[loop_i];
      }
      if (buckets[bucket_index].min == -1 || buckets[bucket_index].min > nums[loop_i]) {
        buckets[bucket_index].min = nums[loop_i];
      }
    }

    int max_space = 0;
    int last_max = -1;

    for (int loop_i = 0; loop_i < bucket_num; ++loop_i) {
      if (buckets[loop_i].max == -1) continue;
      if (last_max == -1) {
        last_max = buckets[loop_i].max;
        continue;
      }
      if (buckets[loop_i].min - last_max > max_space) {
        max_space = buckets[loop_i].min - last_max;
      }
      last_max = buckets[loop_i].max;
    }
    return max_space;
  }
};