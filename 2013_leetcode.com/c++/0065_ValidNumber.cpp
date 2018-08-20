#include <string>
using namespace std;

class Solution {
 public:
  bool isNumber(string s) {
    // "[ ][+|-][ ]int/float[epart3][ ]"
    int i = skipSign(s, 0);
    i = readIntOrFloat(s, i, false);
    if (i == -1) {
      return false;
    }
    if (i < s.length() && s[i] == 'e') {
      i = skipSign(s, i + 1, false);
      i = readDigits(s, i);
      if (i == -1) {
        return false;
      }
    }
    i = skipWhites(s, i);
    return i == s.length();
  }

 private:
  int skipSign(const string& s, int i, const bool allow_space = true) {
    if (allow_space) {
      i = skipWhites(s, i);
    }
    if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
      return i + 1;
    }
    return i;
  }

  // Read "[ ]*[0-9]+" or "[ ]*[0-9]*.[0-9]+"
  int readIntOrFloat(const string& s, int i, const bool allow_space = true) {
    if (i == s.length()) {
      return -1;
    }

    int next = readDigits(s, i, allow_space);
    if (next == -1) {
      // part2 is required.
      if (s[i] != '.') {
        return -1;
      }
      next = readDigits(s, i + 1, false);
      if (next == -1) {
        return -1;
      }
      return next;
    }

    i = next;
    if (s[i] == '.') {
      next = readDigits(s, ++i, false);
    }
    return next > 0 ? next : i;
  }

  // Read "[ ]*[0-9]+"
  int readDigits(const string& s, int i, const bool allow_space = true) {
    if (allow_space) {
      i = skipWhites(s, i);
    }
    if (i == s.length() || s[i] < '0' || s[i] > '9') {
      return -1;
    }
    while (i < s.length() && isdigit(s[i])) {
      ++i;
    }
    return i;
  }

  // Read "[ ]*"
  int skipWhites(const string& s, int i) {
    while (i < s.length() && isspace(s[i])) {
      ++i;
    }
    return i;
  }
};
