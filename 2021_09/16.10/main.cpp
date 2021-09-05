#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        std::map<int, int> year_count;
        for (auto year_item : birth) {
            year_count[year_item]++;
        }
        for (auto year_item : death) {
            year_count[year_item + 1]--;
        }
        
        int people = 0;
        int max_people = 0;
        int max_year = 0;
        for (auto item : year_count) {
            people += item.second;
            if (max_people < people) {
                max_people = people;
                max_year = item.first;
            }
        }
        return max_year;
    }
};