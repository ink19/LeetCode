class Solution {
public:
  double myPow2(double x) {
    return x * x;
  }
  double myPow(double x, int n) {
    long long nn = n;
    if (nn < 0) {
      nn = -nn;
      x = 1/x;
    }
    double result = 1;
    double temp = x;
    while (nn != 0) {
      if (nn&1) {
        result *= temp;
      }
      nn >>= 1;
      temp = myPow2(temp);
    }
    return result;
  }
};