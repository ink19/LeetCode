#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    bool findIt(int h, int w, int loop_i, const string &word, vector<vector<char>>& board, vector<vector<bool>>& is_search) {
        if (!(board.size() > h && h >= 0 && board[0].size() > w && w >= 0)) return false; 
        
        if (is_search[h][w]) return false;
        if (board[h][w] != word[loop_i]) {
            return false;
        }
        
        is_search[h][w] = true;
        
        if (word.size() - 1 == loop_i) return true;
        bool result = findIt(h + 1, w, loop_i + 1, word, board, is_search);
        if (result) return true;
        result = findIt(h - 1, w, loop_i + 1, word, board, is_search);
        if (result) return true;
        result = findIt(h, w + 1, loop_i + 1, word, board, is_search);
        if (result) return true;
        result = findIt(h, w - 1, loop_i + 1, word, board, is_search);
        if (result) return true;
        is_search[h][w] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        std::vector<vector<bool>> is_search(board.size(), vector<bool>(board[0].size(), false));
        for (int loop_i = 0; loop_i < board.size(); ++loop_i) {
            for (int loop_j = 0; loop_j < board[0].size(); ++loop_j) {
                if (findIt(loop_i, loop_j, 0, word, board, is_search)) {
                    return true;
                }
                std::cout << std::endl;
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<char>> data = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string s = "SEE";
    std::cout << Solution().exist(data, s) << std::endl;
    return 0;
}