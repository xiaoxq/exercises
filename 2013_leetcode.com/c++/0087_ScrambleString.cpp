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
                  vector<vector<vector<CacheStatus>>>& cache,
                  int start1, int start2, int len) {
    if (cache[start1][start2][len] != UNINITED) {
      return cache[start1][start2][len] == IS_SCRAMBLE;
    }

    // Check charset.
    vector<int> charCount(26, 0);
    for (int i = 0; i < len; ++i) {
      ++charCount[s1[start1 + i] - 'a'];
      --charCount[s2[start2 + i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (charCount[i] != 0) {
        cache[start1][start2][len] = IS_NOT_SCRAMBLE;
        return false;
      }
    }

    if (len <= 2) {
      cache[start1][start2][len] = IS_SCRAMBLE;
      return true;
    }

    for (int i = 1; i < len; ++i) {
      if ((isScramble(s1, s2, cache, start1, start2, i) &&
           isScramble(s1, s2, cache, start1 + i, start2 + i, len - i)) ||
          (isScramble(s1, s2, cache, start1, start2 + len - i, i) &&
           isScramble(s1, s2, cache, start1 + i, start2, len - i))) {
        cache[start1][start2][len] = IS_SCRAMBLE;
        return true;
      }
    }
    cache[start1][start2][len] = IS_NOT_SCRAMBLE;
    return false;
  }
};
