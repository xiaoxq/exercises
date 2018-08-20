#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    letterCombinations(digits, 0, "", &result);
    return result;
  }

 private:
  void letterCombinations(const string& digits, const int index,
                          const string& prefix, vector<string>* result) {
    static const string digit2char[10] =
        {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (index == digits.size()) {
      if (!prefix.empty()) {
        result->push_back(prefix);
      }
      return;
    }
    for (const char candidate : digit2char[digits[index] - '0']) {
      letterCombinations(digits, index + 1, prefix + candidate, result);
    }
  }
};
