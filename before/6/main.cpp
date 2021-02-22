#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        const int loopn = numRows * 2 - 2;
        const int str_len = s.size();
        string result = "";
        int temp_index1 = 1;
        int temp_index2 = -1;    
        for (int loop_i = 0; loop_i < numRows; ++loop_i) {
            temp_index1--;
            temp_index2++;
            int index1 = temp_index1;
            int index2 = temp_index2;
            while (index2 < str_len || index1 < str_len) {
                if (index1 >= 0) {
                    if (loop_i != 0 && loop_i != numRows - 1) {
                        result.push_back(s.at(index1));
                    }
                }
                if (index2 < str_len)
                result.push_back(s.at(index2));

                index1 += loopn;
                index2 += loopn;
            }
        }
        return result;
    }
};


int main() {
    Solution s;
    std::cout << s.convert("LEETCODEISHIRING", 4) << std::endl;
    return 0;
}