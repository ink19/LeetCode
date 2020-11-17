#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int room_number = rooms.size();
        if (room_number == 0) return true;
        std::vector<int> can_visited(room_number, 0);
        std::vector<int> visit_list;
        can_visited[0] = 1;
        visit_list.push_back(0);
        while (!visit_list.empty()) {
            const int temp_room = visit_list.back();
            visit_list.pop_back();
            for (auto& key: rooms[temp_room]) {
                if (can_visited[key] == 0) {
                    visit_list.push_back(key);
                    can_visited[key] = 1;
                }
            }
        }

        for (int loop_i = 0; loop_i < room_number; ++loop_i) {
            if (can_visited[loop_i] == 0) return false;
        }
        return true;
    }
};

int main() {
    Solution s;

}