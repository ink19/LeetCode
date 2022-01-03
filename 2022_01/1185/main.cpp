#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const string week_name[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

class Solution {
public:
  string dayOfTheWeek(int day, int month, int year) {
    tm gtm;
    memset(&gtm, 0, sizeof(tm));
    gtm.tm_year = year - 1900;
    gtm.tm_mon = month - 1;
    gtm.tm_mday = day;
    time_t ti = mktime(&gtm);
    int index = (ti / (3600 * 24) + 4) % 7;
    return week_name[index];
  }
};