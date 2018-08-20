#include <climits>
#include <string>
using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    size_t pos = str.find_first_not_of(" \t\n");
    if (pos == string::npos) {
      return 0;
    }
    const bool is_neg = str[pos] == '-';
    if (is_neg || str[pos] == '+') {
      ++pos;
    }
    if (pos == str.length() || str[pos] < '0' || str[pos] > '9') {
      return 0;
    }

    int result = 0;
    while (pos < str.length() && str[pos] >= '0' && str[pos] <= '9') {
      const int next_result = result * 10 + (str[pos] - '0');
      if (next_result / 10 != result) {
        return is_neg ? INT_MIN : INT_MAX;
      }
      result = next_result;
      ++pos;
    }
    return is_neg ? -result : result;
  }
};
