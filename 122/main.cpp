#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int status = 0;
        int profit = 0;
        int buy_price = 0;
        prices.push_back(-1);
        for (int loop_i = 1; loop_i < static_cast<int>(prices.size()); ++loop_i) {
            if (status == 0) {
                if (prices[loop_i] > prices[loop_i - 1]) {
                    status = 1;
                    buy_price = prices[loop_i - 1];
                }
            } else {
                if (prices[loop_i] < prices[loop_i - 1]) {
                    status = 0;
                    profit += (prices[loop_i - 1] - buy_price);
                } 
            }
        }

        return profit;
    }
};