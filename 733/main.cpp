#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        std::queue<std::pair<int, int> > index_queue;
        const int source_color = image[sr][sc];
        if (source_color == newColor) return image;
        index_queue.push(std::make_pair(sr, sc));
        const int height = image.size();
        const int width = image.at(0).size();
        while (!index_queue.empty()) {
            auto now_index = index_queue.front();
            index_queue.pop();
            image[now_index.first][now_index.second] = newColor;
            if (now_index.first != 0 && image[now_index.first - 1][now_index.second] == source_color) {
                index_queue.push(std::make_pair(now_index.first - 1, now_index.second));
            }
            
            if (now_index.first != height - 1 && image[now_index.first + 1][now_index.second] == source_color) {
                index_queue.push(std::make_pair(now_index.first + 1, now_index.second));
            }
            
            if (now_index.second != 0 && image[now_index.first][now_index.second - 1] == source_color) {
                index_queue.push(std::make_pair(now_index.first, now_index.second - 1));
            }

            if (now_index.second != width - 1 && image[now_index.first][now_index.second + 1] == source_color) {
                index_queue.push(std::make_pair(now_index.first, now_index.second + 1));
            }
        }
        return image;
    }
};

int main() {

    return 0;
}