#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
    const int img_height = img.size();
    const int img_width = img[0].size();
    vector<vector<int>> out_data(img_height, vector<int>(img_width, 0));

    for (int loop_i = 0; loop_i < img_height; ++loop_i) {
      for (int loop_j = 0; loop_j < img_width; ++loop_j) {
        int sum = 0, num = 0;
        add_num(img, loop_i - 1, loop_j - 1, sum, num);
        add_num(img, loop_i - 1, loop_j, sum, num);
        add_num(img, loop_i - 1, loop_j + 1, sum, num);
        add_num(img, loop_i, loop_j - 1, sum, num);
        add_num(img, loop_i, loop_j, sum, num);
        add_num(img, loop_i, loop_j + 1, sum, num);
        add_num(img, loop_i + 1, loop_j - 1, sum, num);
        add_num(img, loop_i + 1, loop_j, sum, num);
        add_num(img, loop_i + 1, loop_j + 1, sum, num);
        out_data[loop_i][loop_j] = sum / num;
      }
    }
    return out_data;
  }
  
  void add_num(const vector<vector<int>> &img, const int &height, const int &width, int &sum, int &num) {
    const int img_height = img.size();
    const int img_width = img[0].size();
    if (height >= 0 && height < img_height && width >= 0 && width < img_width) {
      sum += img[height][width];
      num++;
    }
  }
};