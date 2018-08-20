#include <vector>

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    std::vector<int> digits;
    digits.reserve(sizeof(int) * 3);
    while (x > 0) {
      digits.push_back(x % 10);
      x /= 10;
    }
    for (int i = 0, j = digits.size() - 1; i < j; ++i, --j) {
      if (digits[i] != digits[j]) {
        return false;
      }
    }
    return true;
  }
};
