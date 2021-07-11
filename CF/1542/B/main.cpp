#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
int main() {
  int N;
  long long a, b, n;
  scanf("%d", &N);
  while (N--) {
    scanf("%lld%lld%lld", &n, &a, &b);
    if ((n - 1) % b == 0) {
      std::cout << "Yes" << std::endl;
      continue;
    } else {
      if (a == 1) {
        std::cout << "No" << std::endl;
        continue;
      } 
    }
    
    
    long long temp_n = 1;
    bool flag = false;

    while(temp_n * a <= n) {
      temp_n = temp_n * a;
      if ((n - temp_n) % b == 0) {
        std::cout << "Yes" << std::endl;
        flag = true;
        break;
      }
    }
    if (!flag) {
      std::cout << "No" << std::endl;
    }
  }
  return 0;
}