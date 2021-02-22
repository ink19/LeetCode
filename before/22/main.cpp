#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> result;
    
    void genP(string st, int left, int right) {
        if (left == 0 && right == 0) result.push_back(st);
        if (left != 0) {
            genP(st + '(', left - 1, right + 1);
        }
        
        if (right != 0) {
            genP(st + ')', left, right - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        genP("", n, 0);
        return result;
    }
};
