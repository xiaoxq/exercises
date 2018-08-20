#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int start = 0, end;
    while (start < words.size()) {
      const int len = getWords(words, maxWidth, &start, &end);
      if (end - start == 1 || end == words.size()) {
        result.push_back(leftJustified(words, maxWidth, start, end));
      } else {
        result.push_back(fullyJustified(words, maxWidth, len, start, end));
      }
      start = end;
    }
    return result;
  }

 private:
  int getWords(const vector<string>& words, const int maxWidth,
                int* start, int* end) {
    int& i = *end;
    int len = -1;
    for (i = *start; i < words.size(); ++i) {
      if (len + 1 + words[i].length() > maxWidth) {
        return len;
      }
      len += words[i].length() + 1;
    }
    return len;
  }

  string fullyJustified(const vector<string>& words, const int maxWidth,
                        const int len, int start, int end) {
    string result;
    result.reserve(maxWidth);
    int whiteSpaces = maxWidth - len;
    int whiteSpaceSlots = end - start - 1;
    int avgSpaces = whiteSpaces / whiteSpaceSlots + 1;
    int extraSpaceSlots = whiteSpaces % whiteSpaceSlots;
    for (int i = start; i < end; ++i) {
      result.append(words[i]);
      if (i + 1 < end) {
        if (i - start < extraSpaceSlots) {
          result.append(avgSpaces + 1, ' ');
        } else {
          result.append(avgSpaces, ' ');
        }
      }
    }
    return result;
  }

  string leftJustified(const vector<string>& words, const int maxWidth,
                       int start, int end) {
    string result;
    result.reserve(maxWidth);

    int len = 0;
    for (int i = start; i < end; ++i) {
      if (i > start) {
        result.append(1, ' ');
        ++len;
      }
      result.append(words[i]);
      len += words[i].length();
    }
    if (len < maxWidth) {
      result.append(maxWidth - len, ' ');
    }

    return result;
  }
};
