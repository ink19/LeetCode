#include <iostream>
#include <ostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <queue>

int main() {
    int n; 
    long long m;
    scanf("%d%lld", &n, &m);

    std::map<int, std::set<int>> map_fee;

    for (int loop_i = 0; loop_i < m; ++loop_i) {
        int temp_i, temp_j;
        scanf("%d%d", &temp_i, &temp_j);
        map_fee[temp_i - 1].insert(temp_j - 1);
        map_fee[temp_j - 1].insert(temp_i - 1);
    }

    std::set<int> un_visit;
    
    for (int loop_i = 0; loop_i < n; ++loop_i) {
        map_fee[loop_i].insert(loop_i);
        un_visit.insert(loop_i);
    }

    std::vector<int> visit(n, 0);
    int vn = 1;
    std::queue<int> queue;
    std::map<int, long long> mn;
    std::vector<int> need_remove;
    for (int loop_i = 0; loop_i < n; ++loop_i) {
        if (visit[loop_i] != 0) continue;
        queue.push(loop_i);
        visit[loop_i] = vn;
        mn[vn]++;
        un_visit.erase(un_visit.find(loop_i));
        
        while (!queue.empty()) {
            auto mtop = queue.front();
            queue.pop();
            need_remove.clear();
            for (auto loop_j : un_visit) {
                if (map_fee[mtop].find(loop_j) == map_fee[mtop].end()) {
                    // std::cout << loop_j << std::endl;
                    queue.push(loop_j);
                    visit[loop_j] = vn;
                    mn[vn]++;
                    need_remove.push_back(loop_j);
                }
            }
            for (int loop_j = 0; loop_j < need_remove.size(); ++loop_j) {
                un_visit.erase(un_visit.find(need_remove[loop_j]));
            }
        }
        vn++;
    }
    long long result = 0;
    for (auto item : mn) {
        result += (item.second) * (item.second - 1) / 2;
    }
    printf("%lld\n", result);
    return 0;
}