#include <string>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
   int longest = 0, start = 0;
   for (int center = 0; center < s.length() - longest / 2; ++center ) {
      const int current = max(
          // aba, centerPos point at b
          getPalindromeLen(s, center - 1, center + 1),
          // abba, centerPos point at 2nd b
          getPalindromeLen(s, center - 1, center));
      if (current > longest) {
        longest = current;
        start = center - current / 2;
      }
    }
    return s.substr(start, longest);
  }

 private:
  int getPalindromeLen(const string& s, int left, int right) {
    const int len = s.length();
    while (left >= 0 && right < len && s[left] == s[right]) {
      --left;
      ++right;
    }
    return right-left-1;
  }
};
