#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::sort(tickets.begin(), tickets.end(), [](const vector<string> &a, const vector<string>&b) {
            if (a[0] == b[0]) return a[1] > b[1];
            else return a[0] > b[0];
        });

        for (int loop_i = 0; loop_i < tickets.size(); ++loop_i) {
            std::cout << tickets[loop_i][0] << " " << tickets[loop_i][1] << std::endl;
        }

        std::vector<string> result;
        result.push_back("JFK");
        string now_place = "JFK";
        while (!tickets.empty()) {
            for (int loop_i = 0; loop_i < tickets.size(); ++loop_i) {
                if (tickets[loop_i].at(0) == now_place) {
                    now_place = tickets[loop_i].at(1);
                    result.push_back(now_place);
                    tickets.erase(tickets.begin() + loop_i);
                    goto next;
                }
            }

            next:;
        }
        return result;
    }
};

int main() {
    std::vector<std::vector<std::string> > data = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution s;
    s.findItinerary(data);
}