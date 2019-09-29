#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesis("", n, n, &result);
    return result;
  }

 private:
  void generateParenthesis(const string& prefix, const int open_remain,
                           const int close_remain, vector<string>* result) {
    // reach the end
    if (open_remain == 0 && close_remain == 0) {
      result->push_back(prefix);
      return;
    }

    // open one
    if (open_remain > 0) {
      generateParenthesis(prefix + "(", open_remain - 1, close_remain, result);
    }
    // close one
    if (close_remain > open_remain) {
      generateParenthesis(prefix + ")", open_remain, close_remain - 1, result);
    }
  }
};
