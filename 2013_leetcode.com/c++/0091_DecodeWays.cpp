#include <string>
using namespace std;

class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty()) {
      return 0;
    }
    int pre_pre = 1, pre = 1;
    for (int i = 0; i < s.length(); ++i) {
      int cur = 0;
      // Take one char.
      if (s[i] != '0') {
        cur = pre;
      }
      // Take two chars.
      if (i > 0 && (
          s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
        cur += pre_pre;
      }
      pre_pre = pre;
      pre = cur;
    }
    return pre;
  }
};
