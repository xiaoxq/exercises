#include <string>
using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int pi = 0;
    int last_pi = -1;
    int last_si = 0;

    for (int si = 0; si < s.length();) {
      // one * and multiple *, same effect
      while (pi < p.length() && p[pi] == '*') {
        last_si = si;
        last_pi = ++pi;  // initially match 0 character
      }

      // not match
      if (pi == p.length() || (p[pi] != s[si] && p[pi] != '?')) {
        if (last_pi < 0) {
          return false;
        }
        pi = last_pi;
        si = ++last_si;  // match 1 more character
      } else {
        ++si;
        ++pi;
      }
    }

    while (pi < p.length() && p[pi] == '*') {
      ++pi;
    }
    return pi == p.length();
  }
};
