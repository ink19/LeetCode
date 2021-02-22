#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      const int flowerbed_len = flowerbed.size();

      if (n == 0) return true;
      if (flowerbed_len == 1) {
        if (flowerbed[0] == 1) return false;
        else return true;
      }

      if (flowerbed[1] == 0 && flowerbed[0] == 0) {
        flowerbed[0] = 1;
        n--;
      }

      if (flowerbed[flowerbed_len - 2] == 0 && flowerbed[flowerbed_len - 1] == 0) {
        flowerbed[flowerbed_len - 1] = 1;
        n--;
      }

      if (n <= 0) return true;

      for (int loop_i = 1; loop_i < flowerbed_len - 1; ++loop_i) {
        if (flowerbed[loop_i] == 0 && flowerbed[loop_i - 1] == 0 && flowerbed[loop_i + 1] == 0) {
          flowerbed[loop_i] = 1;
          n--;
          if (n <= 0) return true;
        } 
      }
      
      return false;
    }
};