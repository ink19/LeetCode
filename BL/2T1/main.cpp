#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

class Solu {
public:
    int solve(std::vector<std::string> &expr) {
        const int expr_len = expr.size();
        std::stack<int> tresult;
        tresult.push(std::atoi(expr[0].data()));
        for (int loop_i = 1; loop_i < expr_len; loop_i += 2) {
            if (expr[loop_i] == "/" || expr[loop_i] == "*") {
                int a = tresult.top();
                tresult.pop();
                if (expr[loop_i] == "/") {
                    tresult.push(a / std::atoi(expr[loop_i + 1].data()));
                } else {
                    tresult.push(a * std::atoi(expr[loop_i + 1].data()));
                }
            } else {
                if (expr[loop_i] == "+") {
                    tresult.push(std::atoi(expr[loop_i + 1].data()));
                } else {
                    tresult.push(- std::atoi(expr[loop_i + 1].data()));
                }
            }
        }

        int result = 0;

        while (!tresult.empty()) {
            result += tresult.top();
            tresult.pop();
        }

        return result;
    }
};

int main() {
    std::vector<std::string> data = {"1", "+", "3", "/", "3", "*", "4"};
    std::cout << Solu().solve(data) << std::endl;
    return 0;
}