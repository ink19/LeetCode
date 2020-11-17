#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int len = moves.size();
        int h = 0;
        int v = 0;
        for (int loop_i = 0;  loop_i < len; ++loop_i) {
            switch (moves[loop_i])
            {
            case 'U':
                h++;
                break;
            case 'D':
                h--;
                break;
            case 'R':
                v++;
                break;
            case 'L':
                v--;
                break;
            default:
                break;
            }
        }
        if (h == 0 && v == 0) return true;
        else return false;
    }
};

int main() {

}