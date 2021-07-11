#include <iostream>
#include <string>
#include <stdio.h>
#include <numeric>
#include <algorithm>

long long gcd(long long a,long long b) {
    return b>0 ? gcd(b,a%b):a;
}

long long F(long long i) {
  if (i == 1) return 2;
  // i %= (1000000000 + 7);
  // std::cout << i << std::endl;
  long long result = 0;

  int max_x = 1;
  long long temp_l = 1;
  while (temp_l <= i) {
    max_x++;
    temp_l *= max_x / gcd(temp_l, max_x);
  }
  result = i%1000000007;
  temp_l = 1;
  for (int loop_i = 1; loop_i <= max_x; ++loop_i) {
    temp_l *= loop_i / gcd(temp_l, loop_i);
    result += (i / temp_l)%1000000007;
    // std::cout << temp_l << std::endl;
    result %= (1000000007);
  }

  return result;
}

int main() {
  long long N, i;
  scanf("%lld", &N);
  while (N--) {
    scanf("%lld", &i);
    printf("%lld\n", F(i));
  }
  return 0;
}