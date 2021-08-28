#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int point_num = points.size();
        std::vector<std::vector<int>> edge_list(point_num, vector<int>(point_num, 0));
        for (int loop_i = 0; loop_i < point_num; ++loop_i) {
            for (int loop_j = 0; loop_j < point_num; ++loop_j) {
                edge_list[loop_i][loop_j] = std::abs(points[loop_i][0] - points[loop_j][0]) + std::abs(points[loop_i][1] - points[loop_j][1]);
            }
        } 
        std::set<int> in_set;
        in_set.insert(0);
        std::priority_queue<std::tuple<int, int, int>, vector<std::tuple<int, int, int>>, std::greater<>> edge_in;
        for (int loop_i = 1; loop_i < point_num; ++loop_i) {
            edge_in.push({edge_list[0][loop_i], 0, loop_i});
        } 
        int result = 0;
        while (in_set.size() != point_num) {
            auto edge = edge_in.top();
            edge_in.pop();
            while (in_set.find(std::get<2>(edge)) != in_set.end()) {
                edge = edge_in.top();
                edge_in.pop();
            }

            result += std::get<0>(edge);
            in_set.insert(std::get<2>(edge));

            for (int loop_i = 0; loop_i < point_num; ++loop_i) {
                if (in_set.find(loop_i) == in_set.end()) {
                    edge_in.push({edge_list[std::get<2>(edge)][loop_i], std::get<2>(edge), loop_i});
                }
            }
        }
        return result;
    }
};