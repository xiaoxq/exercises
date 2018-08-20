#include <vector>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
      return false;
    }

    // Binary search on rows.
    int up = 0, down = matrix.size();
    while (up + 1 < down) {
      int mid = (up + down) / 2;
      if (matrix[mid][0] <= target) {
        up = mid;
      } else {
        down = mid;
      }
    }

    // Binary search on row[up].
    int left = 0, right = matrix[up].size();
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      if (matrix[up][mid] < target) {
        left = mid;
      } else if (matrix[up][mid] > target) {
        right = mid;
      } else {
        return true;
      }
    }
    return matrix[up][left] == target;
  }
};
