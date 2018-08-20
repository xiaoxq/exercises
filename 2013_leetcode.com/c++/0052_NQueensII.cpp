#include <vector>
using namespace std;

class Solution {
 public:
  int totalNQueens(int n) {
    // (x,y) will occupy colMark[y]
    vector<bool> colMark(n, false);
    // (x,y) will occupy upLeftMark[n-1+x-y]
    vector<bool> upLeftMark(2 * n - 1, false);
    // (x,y) will occupy upLeftMark[x+y]
    vector<bool> upRightMark(2 * n - 1, false);

    return tryPlace( n, 0, colMark, upLeftMark, upRightMark );
  }

 private:
  int tryPlace(int n, int curRow, vector<bool>& colMark,
               vector<bool>& upLeftMark, vector<bool>& upRightMark) {
    // reach the end
    if (curRow == n) {
      return 1;
    }

    int result = 0;
    // try every col[j]
    for (int j = 0; j < n; ++j) {
      if (colMark[j] || upLeftMark[n - 1 + curRow - j] || upRightMark[curRow + j]) {
        continue;
      }
      // find a slot here
      colMark[j] = upLeftMark[n - 1 + curRow - j] = upRightMark[curRow + j] = true;
      result += tryPlace(n, curRow + 1, colMark, upLeftMark, upRightMark);
      colMark[j] = upLeftMark[n - 1 + curRow - j] = upRightMark[curRow + j] = false;
    }
    return result;
  }
};
