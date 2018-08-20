#include <string>
#include <unordered_map>
using namespace std;

bool CheckPermutation(const string& str1, const string& str2) {
  if (str1.length() != str2.length()) {
    return false;
  }

  unordered_map<char, int> char_count;
  for (const char ch : str1) {
    if (char_count.find(ch) == char_count.end()) {
      char_count[ch] = 1;
    } else {
      ++char_count[ch];
    }
  }
  for (const char ch : str2) {
    if (char_count.find(ch) == char_count.end()) {
      return false;
    } else {
      --char_count[ch];
      if (char_count[ch] < 0) {
        return false;
      }
    }
  }
  return true;
}
