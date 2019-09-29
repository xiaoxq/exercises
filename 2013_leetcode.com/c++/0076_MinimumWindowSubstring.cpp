#include <climits>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> requirements;
    unordered_map<char, int> fulfilled;
    for (const char ch : t) {
      if (requirements.find(ch) == requirements.end()) {
        requirements[ch] = 1;
      } else {
        ++requirements[ch];
      }
      fulfilled[ch] = 0;
    }

    int min_start = -1, min_len = INT_MAX;
    int next_start = 0;
    int fulfilled_count = 0;
    for (int i = 0; i < s.length(); ++i) {
      // We don't need this char.
      if (requirements.find(s[i]) == requirements.end()) {
        continue;
      }
      if (++fulfilled[s[i]] == requirements[s[i]]) {
        if (++fulfilled_count == requirements.size()) {
          --fulfilled_count;
          int start, len;
          checkOut(requirements, s, i, &fulfilled, &next_start, &start, &len);
          if (len < min_len) {
            min_len = len;
            min_start = start;
          }
        }
      }
    }
    return min_start >= 0 ? s.substr(min_start, min_len) : "";
  }

 private:
  void checkOut(const unordered_map<char, int>& requirements, const string& s,
                int right, unordered_map<char, int>* fulfilled, int* next_start,
                int* start, int* len) {
    for (int i = *next_start; i < s.length(); ++i) {
      if (requirements.find(s[i]) == requirements.end()) {
        continue;
      }
      if (--(*fulfilled)[s[i]] < requirements.at(s[i])) {
        *start = i;
        *len = right - i + 1;
        *next_start = i + 1;
        break;
      }
    }
  }
};
