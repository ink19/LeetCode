#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        const int s_len = s.size();
        const int p_len = p.size();
        if (s_len == 0 && p_len == 0) return true;
        if (s_len != 0 && p_len == 0) return false;
        
        int loop_s = 0, loop_p = 0;
        char need_match = ' ';
        
    }
};


int main() {

}