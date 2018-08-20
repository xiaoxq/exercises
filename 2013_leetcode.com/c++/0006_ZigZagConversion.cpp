#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    vector<string> rows(numRows);
    const int len = s.length();

    int pos = 0;
    for (int col = 0; ; ++col) {
      if (col % 2 == 0) {
        for (int i = 0; i < numRows && pos < len; ++i) {
          rows[i].append(1, s[pos++]);
        }
      } else {
        for (int i = numRows - 2; i >= 1 && pos < len; --i) {
          rows[i].append(1, s[pos++]);
        }
      }
      if (pos == len) {
        break;
      }
    }

    string result;
    for (const string& row : rows) {
      result.append(row);
    }
    return result;
  }
};
