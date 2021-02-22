#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sqkClosest(vector<vector<int>>::iterator points_begin, vector<vector<int>>::iterator points_end, int K) {
        auto temp_points_begin = points_begin;
        auto temp_points_end = points_end;
        int center_point = (*points_begin)[0] * (*points_begin)[0] + (*points_begin)[1] * (*points_begin)[1];
        temp_points_begin++;
        while (temp_points_begin != temp_points_end) {
            if (center_point < (*temp_points_begin)[0] * (*temp_points_begin)[0] + (*temp_points_begin)[1] * (*temp_points_begin)[1]) {
                std::iter_swap(temp_points_begin, --temp_points_end);
            } else {
                temp_points_begin++;
            }
        }
        std::iter_swap(temp_points_begin - 1, points_begin);
        if (K == (temp_points_begin - points_begin)) return;
        if (K > (temp_points_begin - points_begin)) {
            sqkClosest(temp_points_begin, points_end, K - (temp_points_begin - points_begin));
            return;
        } else {
            sqkClosest(points_begin, temp_points_begin - 1, K);
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sqkClosest(points.begin(), points.end(), K);
        points.resize(K);
        return points;
    }
};