#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Solution {
public:
  int dayOfYear(string date) {
    int year, month, day;
    std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    bool isRun = false;
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) isRun = true;
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count_month[12] = {0};
    int sum = 0;
    for (int loop_i = 0; loop_i < 11; ++loop_i) {
      count_month[loop_i + 1] = months[loop_i] + sum;
      sum = count_month[loop_i + 1]; 
    }
    day += count_month[month - 1];
    if (month > 2 && isRun) day++;
    return day;
  }
};