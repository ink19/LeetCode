#include <iostream>
#include <string>
#include <stdio.h>


int main() {
  int N = 0, n = 0, temp_i = 0;
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &n);
    int n2 = n * 2;
    for (int loop = 0; loop < n2; ++loop) {
      scanf("%d", &temp_i);
      if (temp_i % 2 == 1) {
        n--;
      }
    }
    if (n == 0) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }
  return 0;
}