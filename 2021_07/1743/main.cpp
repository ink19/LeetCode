#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        const int pair_len = adjacentPairs.size();
        std::map<int, std::vector<int>> graph;
        for (int loop_i = 0; loop_i < pair_len; ++loop_i) {
            if (graph.count(adjacentPairs[loop_i][0]) == 0) {
                graph[adjacentPairs[loop_i][0]] = std::vector<int>({adjacentPairs[loop_i][1]});
            } else {
                graph[adjacentPairs[loop_i][0]].push_back(adjacentPairs[loop_i][1]);
            }

            if (graph.count(adjacentPairs[loop_i][1]) == 0) {
                graph[adjacentPairs[loop_i][1]] = std::vector<int>({adjacentPairs[loop_i][0]});
            } else {
                graph[adjacentPairs[loop_i][1]].push_back(adjacentPairs[loop_i][0]);
            }
        }
        std::vector<int> result;
        int then_it = 0;
        for (auto mpair : graph) {
            if (mpair.second.size() == 1) {
                result.push_back(mpair.first);
                result.push_back(mpair.second[0]);
                then_it = mpair.second[0];
                break;
            }
        }
        while (graph[then_it].size() != 1) {
            if (graph[then_it][0] == *(result.end() - 2)) {
                result.push_back(graph[then_it][1]);
                then_it = graph[then_it][1];
            } else {
                result.push_back(graph[then_it][0]);
                then_it = graph[then_it][0];
            }
        }

        return result;
    }
};
