#include <string>
using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    return isMatch(s, 0, p, 0);
  }

 private:
  bool isMatch(const string& s, size_t s_index,
               const string& p, size_t p_index) {
    if (p.length() == p_index) {
      return s.length() == s_index;
    }
    const char cur = p[p_index];

    // next char is not '*': must match current character
    if (p_index + 1 == p.length() || p[p_index + 1] != '*') {
      if (s_index == s.length()) {
        return false;
      }
      if (cur != '.' && cur != s[s_index]) {
        return false;
      }
      return isMatch(s, s_index + 1, p, p_index + 1);
    }

    // next char is '*': match with lenth [0, ...)
    if (isMatch(s, s_index, p, p_index + 2)) {
      return true;
    }
    for (; s_index < s.length(); ++s_index) {
      if (cur == s[s_index] || cur == '.') {
        if (isMatch(s, s_index + 1, p, p_index + 2)) {
          return true;
        }
      } else {
        break;
      }
    }
    return false;
  }
};
