#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isScramble(string s1, string s2) {
    const int len = s1.length();
    if (s2.length() != len) {
      return false;
    }

    // cache[start_point1][start_point2][len]
    vector<vector<vector<CacheStatus>>> cache(
        len, vector<vector<CacheStatus>>(
                 len, vector<CacheStatus>(len + 1, UNINITED)));
    return isScramble(s1, s2, cache, 0, 0, len);
  }

 private:
  enum CacheStatus {
    UNINITED,
    IS_SCRAMBLE,
    IS_NOT_SCRAMBLE,
  };

  bool isScramble(const string& s1, const string& s2,
                  vector<vector<vector<CacheStatus>>>& cache, int start1,
                  int start2, int len) {
    CacheStatus& cached = cache[start1][start2][len];
    if (cached != UNINITED) {
      return cached == IS_SCRAMBLE;
    }
    if (len == 1) {
      cached = (s1[start1] == s2[start2]) ? IS_SCRAMBLE : IS_NOT_SCRAMBLE;
    } else {
      for (int i = 1; i < len; ++i) {
        if ((isScramble(s1, s2, cache, start1, start2, i) &&
             isScramble(s1, s2, cache, start1 + i, start2 + i, len - i)) ||
            (isScramble(s1, s2, cache, start1, start2 + len - i, i) &&
             isScramble(s1, s2, cache, start1 + i, start2, len - i))) {
          cached = IS_SCRAMBLE;
          break;
        }
      }
    }
    if (cached != IS_SCRAMBLE) {
      cached = IS_NOT_SCRAMBLE;
      return false;
    }
    return true;
  }
};
