#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


typedef struct {
  union {
    char data_c;
    int data_i;
  } data;
  int data_type;
} data_t;

class Solution {
public:
  bool isDig(char c) {
    if (c >= '0' && c <= '9') return true;
    return false;
  }
  bool nextDigest(std::string::iterator &now, std::string::iterator end, int& data) {
    int num = 0;
    while (now != end && isDig(*now)) {
      num *= 10;
      num += *now - '0';
      now++;
    }
    data = num;
    return true;
  }
  bool nextData(std::string::iterator &now, std::string::iterator end, int &data, int &data_type) {
    while(now != end && *now == ' ') now++;
    if (now == end) return false;

    if (isDig(*now)) {
      nextDigest(now, end, data);
      data_type = 1;
      return true;
    }

    data = *now;
    data_type = 2;
    now++;
    return true;
  }
  int calculate(string s) {
    std::stack<data_t> data_stack;
    while (true) {
      
    }
  }
};