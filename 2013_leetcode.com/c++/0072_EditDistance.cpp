#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    const int len1 = word1.length();
    const int len2 = word2.length();
    if (len1 == 0 || len2 == 0) {
      return max(len1, len2);
    }

    vector<vector<int>> dist(len1, vector<int>(len2, -1));
    return minDistance(word1, len1, word2, len2, dist);
  }

 private:
  // Only check word1[0, end1) vs word2[0, end2).
  int minDistance(const string& word1, const int end1,
                  const string& word2, const int end2,
                  vector<vector<int>>& dist) {
    if (end1 == 0 || end2 == 0) {
      return max(end1, end2);
    }
    int& cache = dist[end1 - 1][end2 - 1];
    if (cache >= 0) {
      return cache;
    }

    if (word1[end1 - 1] == word2[end2 - 1]) {
      cache = minDistance(word1, end1 - 1, word2, end2 - 1, dist);
    } else {
      cache = 1 + min({
          minDistance(word1, end1 - 1, word2, end2, dist),
          minDistance(word1, end1, word2, end2 - 1, dist),
          minDistance(word1, end1 - 1, word2, end2 - 1, dist)});
    }
    return cache;
  }
};
