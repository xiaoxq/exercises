class Solution {
 public:
  int reverse(int x) {
    const bool is_neg = (x < 0);
    if (is_neg) {
      x = -x;
    }

    int result = 0;
    while (x > 0) {
      const int next_result = result * 10 + x % 10;
      if (next_result / 10 != result) {
        return 0;
	  }
      result = next_result;
      x /= 10;
    }
    return is_neg ? -result : result;
  }
};
