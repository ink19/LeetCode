#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;
class Solution {
public:
    /* Write Code Here */
    vector<int> exec_data(string data) {
        vector<int> result;
        for (int loop_i = 0; loop_i < data.size(); ++loop_i) {
            if (data[loop_i] == '[' || data[loop_i] == ',') {
                loop_i++;
                int temp_result = 0;
                sscanf(data.data() + loop_i, "%d", &temp_result);
                result.push_back(temp_result);
            }
        }
        return result;
    }
    int check(string input, int rule_cnt, string rules) {
        std::vector<std::vector<int>> data_publisher(rule_cnt, std::vector<int>(2, 0));
        int block_feed = 0;

        auto input_v = exec_data(input);
        auto rules_v = exec_data(rules);

        const int input_len = input_v.size();
        for (int loop_i = 0; loop_i < input_len; ++loop_i) {
            bool is_block = false;
            for (int loop_j = 0; loop_j < rule_cnt; ++loop_j) {
                if (data_publisher[loop_j][1]) {
                    if (input_v[loop_i]) {
                        block_feed++;
                    }
                    is_block = true;
                    input_v[loop_i] = 0;
                    break;
                }
            }
            
            for (int loop_j = 0; loop_j < rule_cnt; ++loop_j) {
                if (!is_block && data_publisher[loop_j][0] >= rules_v[loop_j *3 + 1]) {
                    data_publisher[loop_j][1] = rules_v[loop_j * 3 + 2];
                } 

                if (data_publisher[loop_j][1]) {
                    if (input_v[loop_i]) {
                        block_feed++;
                    }
                    is_block = true;
                    input_v[loop_i] = 0;
                    data_publisher[loop_j][1]--;
                }
            }

            for (int loop_j = 0; loop_j < rule_cnt; ++loop_j) {
                data_publisher[loop_j][0] += input_v[loop_i];
                if (rules_v[loop_j * 3] <= loop_i) {
                    data_publisher[loop_j][0] -= input_v[loop_i - rules_v[loop_j * 3]];
                }
            }
        }
        for (int loop_i = 0; loop_i < input_len; ++loop_i) {
            std::cout << input_v[loop_i] << ",";
        }
        std::cout << std::endl;
        return block_feed;
    }
};

int main() {
    int res;

    string _input;
    getline(cin, _input);
    int _rule_cnt;
    cin >> _rule_cnt;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    string _rules;
    getline(cin, _rules);
    Solution *s = new Solution();
    res = s->check(_input, _rule_cnt, _rules);
    cout << res << endl;
    
    return 0;

}
