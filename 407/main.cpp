#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int h = heightMap.size();
        if (h <= 2) return 0;
        const int w = heightMap.at(0).size();
        if (w <= 2) return 0;
        vector<vector<int>> flag_height = vector<vector<int>>(h, vector<int>(w, 0));
        for (int loop_h = 1; loop_h < h - 1; ++loop_h) {
            for (int loop_w = 1; loop_w < w - 1; ++loop_w) {
                flag_height[loop_h][loop_w]= std::max(heightMap[loop_h - 1][loop_w], flag_height[loop_h - 1][loop_w]);
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h + 1][loop_w], flag_height[loop_h + 1][loop_w]));
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h][loop_w - 1], flag_height[loop_h][loop_w - 1]));
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h][loop_w + 1], flag_height[loop_h][loop_w + 1]));
            }
        }

        for (int loop_h = h - 2; loop_h > 0 ; --loop_h) {
            for (int loop_w = 1; loop_w < w - 1; ++loop_w) {
                flag_height[loop_h][loop_w]= std::max(heightMap[loop_h - 1][loop_w], flag_height[loop_h - 1][loop_w]);
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h + 1][loop_w], flag_height[loop_h + 1][loop_w]));
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h][loop_w - 1], flag_height[loop_h][loop_w - 1]));
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h][loop_w + 1], flag_height[loop_h][loop_w + 1]));
            }
        }

        for (int loop_h = 1; loop_h < h - 1; ++loop_h) {
            for (int loop_w = w - 2; loop_w > 0; --loop_w) {
                flag_height[loop_h][loop_w]= std::max(heightMap[loop_h - 1][loop_w], flag_height[loop_h - 1][loop_w]);
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h + 1][loop_w], flag_height[loop_h + 1][loop_w]));
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h][loop_w - 1], flag_height[loop_h][loop_w - 1]));
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h][loop_w + 1], flag_height[loop_h][loop_w + 1]));
            }
        }

        for (int loop_h = h - 2; loop_h > 0; --loop_h) {
            for (int loop_w = w - 2; loop_w > 0; --loop_w) {
                flag_height[loop_h][loop_w]= std::max(heightMap[loop_h - 1][loop_w], flag_height[loop_h - 1][loop_w]);
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h + 1][loop_w], flag_height[loop_h + 1][loop_w]));
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h][loop_w - 1], flag_height[loop_h][loop_w - 1]));
                flag_height[loop_h][loop_w]= std::min(flag_height[loop_h][loop_w], std::max(heightMap[loop_h][loop_w + 1], flag_height[loop_h][loop_w + 1]));
            }
        }


        int result = 0;
        for (int loop_h = 1; loop_h < h - 1; ++loop_h) {
            for (int loop_w = 1; loop_w < w - 1; ++loop_w) {
                std::cout << flag_height[loop_h][loop_w] << std::endl;
                if (flag_height[loop_h][loop_w] > heightMap[loop_h][loop_w]) {
                    result += flag_height[loop_h][loop_w] - heightMap[loop_h][loop_w];
                }
            }
            std::cout << std::endl;
        }
        return result;
    }
};


int main() {
    Solution s;
    vector<vector<int> > data = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    std::cout << s.trapRainWater(data) << std::endl;

    return 0;
}