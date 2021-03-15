class Solution {
public:
  int cuttingRope(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 4;
    long long result = n%3;
    n -= result;
    if (result == 1) {
        result = 4;
        n -= 3;
    }
    if (result == 0) result = 1;
    while (n != 0) {
      result *= 3;
      result %= 1000000007;
      n -= 3;
    }
    return result;
  }
};