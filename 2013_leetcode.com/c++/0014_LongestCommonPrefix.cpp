#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }

    for (int len = 0; len < strs[0].length(); ++len) {
      for (int i = 1; i < strs.size(); ++i) {
        if (strs[i][len] != strs[0][len]) {
          return strs[0].substr(0, len);
        }
      }
    }
    return strs[0];
  }
};
