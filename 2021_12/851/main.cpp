#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  std::vector<int> result;
  std::vector<int> viewed;

  void dfs(const std::vector<std::set<int>>& graph, const vector<int>& quiet, int node) {
    if (viewed[node]) return;
    viewed[node] = 1;
    for (auto& tnode : graph[node]) {
      dfs(graph, quiet, tnode);
    }
    int min_quiet = node;
    for (auto& tnode : graph[node]) {
      if (quiet[min_quiet] > quiet[result[tnode]]) min_quiet = result[tnode];
    }
    result[node] = min_quiet;
  }

  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    const int people_n = quiet.size();
    result = std::vector<int>(quiet.size(), 0);
    viewed = std::vector<int>(quiet.size(), 0);
    std::vector<std::set<int>> graph(people_n, std::set<int>());
    for (int loop_i = 0; loop_i < richer.size(); ++loop_i) {
      graph[richer[loop_i][1]].insert(richer[loop_i][0]);
    }
    for (int loop_i = 0; loop_i < people_n; ++loop_i) {
      dfs(graph, quiet, loop_i);
    }
    return result;
  }
};