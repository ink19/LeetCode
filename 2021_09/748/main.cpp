#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        const int license_size = licensePlate.size();
        std::vector<int> match_vec(26, 0);
        string result = "";
        for (int loop_i = 0; loop_i < license_size; ++loop_i) {
            if (licensePlate[loop_i] >= 'a' && licensePlate[loop_i] <= 'z') {
                match_vec[licensePlate[loop_i] - 'a']++;
            } 

            if (licensePlate[loop_i] >= 'A' && licensePlate[loop_i] <= 'Z') {
                match_vec[licensePlate[loop_i] - 'A']++;
            }
        }

        for (int loop_j  = 0; loop_j < words.size(); ++loop_j) {
            std::vector<int> sub_vec(26, 0);
            auto word = words.at(loop_j);

            for (int loop_i = 0; loop_i < word.size(); ++loop_i) {
                if (word[loop_i] >= 'a' && word[loop_i] <= 'z') {
                    sub_vec[word[loop_i] - 'a']++;
                } 

                if (word[loop_i] >= 'A' && word[loop_i] <= 'Z') {
                    sub_vec[word[loop_i] - 'A']++;
                }
            }
            
            bool flag = false;
            for (int loop_i = 0; loop_i < 26; ++loop_i) {
                if (sub_vec[loop_i] < match_vec[loop_i]) {
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                if (result == "" || word.size() < result.size()) {
                    result = word;
                }
            }

        }

        return result;
    }
};