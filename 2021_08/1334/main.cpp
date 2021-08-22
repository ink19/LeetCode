#include <vector>
#include <limits>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        std::vector<std::vector<int>> graph(n, std::vector<int>(n, std::numeric_limits<int>::max()/4));
        const int edges_len = edges.size();
        for (int loop_i = 0; loop_i < edges_len; ++loop_i) {
            graph[edges[loop_i][0]][edges[loop_i][1]] = edges[loop_i][2];
            graph[edges[loop_i][1]][edges[loop_i][0]] = edges[loop_i][2];
        }

        for (int loop_i = 0; loop_i < n; ++loop_i) {
            graph[loop_i][loop_i] = 0;
        }

        for (int loop_k = 0; loop_k < n; ++loop_k) {
            for (int loop_i = 0; loop_i < n; ++loop_i) {
                for (int loop_j = 0; loop_j < n; ++loop_j) {
                    graph[loop_i][loop_j] = std::min(graph[loop_i][loop_j], graph[loop_i][loop_k] + graph[loop_k][loop_j]);
                }
            }
        }
        int min_data = std::numeric_limits<int>::max()/4;
        int min_index = 0;
        for (int loop_i = 0; loop_i < n; ++loop_i) {
            int data_sum = 0;
            for (int loop_j = 0; loop_j < n; ++loop_j) {
                if (distanceThreshold >= graph[loop_i][loop_j]) {
                    data_sum++;
                }
            }
            std::cout << data_sum << std::endl;
            if (min_data >= data_sum) {
                min_index = loop_i;
                min_data = data_sum;
            }
        }

        return min_index;
    }
};

int main() {
    vector<vector<int>> data = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    
    std::cout << Solution().findTheCity(4, data, 4) << std::endl;
}