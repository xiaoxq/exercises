#include <string>
using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (haystack.length() < needle.length()) {
      return -1;
    }
    for (size_t i = 0; i <= haystack.length() - needle.length(); ++i) {
      bool matched = true;
      for (size_t j = 0; j < needle.length(); ++j) {
        if (haystack[i + j] != needle[j]) {
          matched = false;
          break;
        }
      }
      if (matched) {
        return i;
      }
    }
    return -1;
  }
};
