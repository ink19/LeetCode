#include <functional>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> d(n, 0);
    for (int loop_i = 0; loop_i < n; ++loop_i) {
        scanf("%d", d.data() + loop_i);
    }

    std::priority_queue<std::tuple<int, int>, std::vector<std::tuple<int, int>>> dn;
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>> dn_in;
    
    for (int loop_i = 0; loop_i < n; ++loop_i) {
        dn.push({d[loop_i], loop_i});
    }

    std::vector<std::tuple<int, int>> edge;

    auto mtop = dn.top();
    dn.pop();
    dn_in.push({std::get<0>(mtop), 0, std::get<1>(mtop)});

    while (!dn_in.empty()) {
        auto mtop = dn_in.top();
        dn_in.pop();
    
        for (int loop_i = 0; loop_i < std::get<0>(mtop); ++loop_i) {
            auto mmtop = dn.top();
            dn.pop();
            edge.push_back({std::get<2>(mtop), std::get<1>(mmtop)});

            if (std::get<0>(mmtop) > 1) {
                dn_in.push({std::get<0>(mmtop) - 1, std::get<1>(mtop) - 1, std::get<1>(mmtop)});
            } 
        }
    }

    for (int loop_i = 0; loop_i < edge.size(); ++loop_i) {
        std::cout << std::get<0>(edge[loop_i]) + 1 << " " << std::get<1>(edge[loop_i]) + 1 << std::endl;
    }

    return 0;
}