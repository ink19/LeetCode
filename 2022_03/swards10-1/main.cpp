class Solution {
public:
  int fib(int n) {
    int lastlast = 0;
    int last = 1;
    int now = 1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    for (int loop_i = 1; loop_i < n; ++loop_i) {
      now = (last + lastlast)%static_cast<int>((1e9 + 7));
      lastlast = last;
      last = now;
    }
    return now;
  }
};