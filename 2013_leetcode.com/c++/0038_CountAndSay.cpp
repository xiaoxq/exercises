#include <string>
using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string result("1");
    while (--n > 0) {
      result = nextCountAndSay(result);
    }
    return result;
  }

 private:
  string nextCountAndSay(const string& num) {
    // in the worst case, new string is double size of n
    static char buf[16];

    string result;
    for (size_t start = 0; start < num.length();) {
      size_t end = num.find_first_not_of(num[start], start + 1);
      if (end == string::npos) {
        end = num.length();
      }
      const size_t len = end - start;

      sprintf(buf, "%d%c", len, num[start]);
      result += buf;
      start = end;
    }
    return result;
  }
};
