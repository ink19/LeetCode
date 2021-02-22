#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    int h = 0;
    int w = 0;
    int get_around_boom(vector<vector<char>>& board, pair<int, int> place) {
        int result = 0;
        int x = place.second;
        int y = place.first;
        if (x != 0 && board[y][x - 1] == 'M') {
            result++;
        }
        if (x != w - 1 && board[y][x + 1] == 'M') {
            result++;
        }
        if (y != 0 && board[y - 1][x] == 'M') {
            result++;
        }
        if (y != h - 1 && board[y + 1][x] == 'M') {
            result++;
        }

        if (x != 0 && y != 0 && board[y - 1][x - 1] == 'M') {
            result++;
        }
        if (x != w - 1 && y != h - 1 && board[y + 1][x + 1] == 'M') {
            result++;
        }
        if (y != 0 && x != w - 1 && board[y - 1][x + 1] == 'M') {
            result++;
        }
        if (y != h - 1 && x != 0 && board[y + 1][x - 1] == 'M') {
            result++;
        }
        return result;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        h = board.size();
        w = board.at(0).size();
        vector<pair<int, int>> queue;
        queue.push_back(make_pair(click[0], click[1]));
        while (!queue.empty()) {
            const auto data = queue.back();
            queue.pop_back();
            if (board[data.first][data.second] == 'M') {
                board[data.first][data.second] = 'X';
                return board;
            }
            if (board[data.first][data.second] == 'E') {
                int boom_number = get_around_boom(board, data);
                if (boom_number == 0) {
                    board[data.first][data.second] = 'B';
                    int x = data.second;
                    int y = data.first;

                    if (x != 0 && board[y][x - 1] == 'E') {
                        queue.push_back(make_pair(y, x - 1));
                    }
                    if (x != w - 1 && board[y][x + 1] == 'E') {
                        queue.push_back(make_pair(y, x + 1));
                    }
                    if (y != 0 && board[y - 1][x] == 'E') {
                        queue.push_back(make_pair(y - 1, x));
                    }
                    if (y != h - 1 && board[y + 1][x] == 'E') {
                        queue.push_back(make_pair(y + 1, x));
                    }

                    if (x != 0 && y != 0 && board[y - 1][x - 1] == 'E') {
                        queue.push_back(make_pair(y - 1, x - 1));
                    }
                    if (x != w - 1 && y != h - 1 && board[y + 1][x + 1] == 'E') {
                        queue.push_back(make_pair(y + 1, x + 1));
                    }
                    if (y != 0 && x != w - 1 && board[y - 1][x + 1] == 'E') {
                        queue.push_back(make_pair(y - 1, x + 1));
                    }
                    if (y != h - 1 && x != 0 && board[y + 1][x - 1] == 'E') {
                        queue.push_back(make_pair(y + 1, x - 1));
                    }
                } else {
                    board[data.first][data.second] = boom_number + '0';
                    continue;
                }
            }
        }

        return board;
    }
};