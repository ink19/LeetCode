#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  std::vector<std::vector<std::pair<int, int>>> graph;
  std::vector<int> graph_value;
  
  int max_value = 0;

  int dfs(int maxTime, int now_value, int now_point, std::set<int> pass_point) {
    if (maxTime < 0) return 0;
    if (pass_point.find(now_point) == pass_point.end()) {
      now_value += graph_value[now_point];
      pass_point.insert(now_point);
    }

    if (now_point == 0 && now_value > max_value) {
      max_value = now_value;
    }
    auto edges = graph[now_point];
    for (auto item : edges) {
      dfs(maxTime - item.second, now_value, item.first, pass_point);
    }
    return 0;
  }

  int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime) {
    graph_value = values;
    graph.assign(values.size(), std::vector<std::pair<int, int>>());
    for (int loop_i = 0; loop_i < edges.size(); ++loop_i) {
      graph[edges[loop_i][0]].push_back({edges[loop_i][1], edges[loop_i][2]});
      graph[edges[loop_i][1]].push_back({edges[loop_i][0], edges[loop_i][2]});
    }
    dfs(maxTime, 0, 0, {});
    return max_value;
  }
};