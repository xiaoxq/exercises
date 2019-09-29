#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    int nMax = 0;
    vector<int> pos;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
        pos.push_back(i);
        continue;
      }

      if (!pos.empty() && s[pos.back()] == '(') {
        pos.pop_back();
        if (pos.empty()) {
          nMax = max(nMax, i + 1);
        } else {
          nMax = max(nMax, i - pos.back());
        }
      } else {
        pos.clear();
        pos.push_back(i);
      }
    }
    return nMax;
  }
};