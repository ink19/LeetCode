#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:

    bool is_valid(int s) {
        if (s >= 0 && s <= 255) return true;
        else return false;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int mod_n[] = {1, 10, 100, 1000};
        int str_len = s.size();
        int s1, s2, s3, s4;
        for (int loop_i = 1; loop_i <= 3; ++loop_i) {
            long long ns = std::stoll(s);
            s1 = ns % mod_n[loop_i];
            if (!is_valid(s1)) break;
            long long ns2 = ns / mod_n[loop_i];

            for (int loop_j = 1; loop_j <= 3; ++loop_j) {
                s2 = ns2 % mod_n[loop_j];
                if (!is_valid(s2)) break;
                long long ns3 = ns2 / mod_n[loop_j];
                for (int loop_k = 1; loop_k <= 3; ++loop_k) {

                    s3 = ns3 % mod_n[loop_k];
                    s4 = ns3 / mod_n[loop_k];
                    if (!is_valid(s3)) break;
                    if (!is_valid(s4)) continue;

                    std::string rs = std::to_string(s4) + "." + std::to_string(s3) + "." + std::to_string(s2) + "." + std::to_string(s1);
                    std::string rs2 = std::to_string(s4) + std::to_string(s3) + std::to_string(s2) + std::to_string(s1);
                    if (rs2 != s) {
                        continue;
                    }

                    if (std::find(result.begin(), result.end(), rs) != result.end()) {
                        continue;
                    }

                    result.push_back(rs);
                }
            }
        }
        std::cout << "sb";
        return result;
    }
};

int main() {
    Solution s;
    std::cout << s.restoreIpAddresses("010010").size() << std::endl;
    return 0;
}