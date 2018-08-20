#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) {
      return result;
    }
    for (int left = 0, right = matrix[0].size(), up = 0, down = matrix.size();
         left < right && up < down;
         ++left, --right, ++up, --down) {
      spiralOrder(matrix, left, right, up, down, &result);
    }
    return result;
  }

 private:
  void spiralOrder(const vector<vector<int>>& matrix,
                   const int left, const int right, const int up, const int down,
                   vector<int>* result) {
    // m[up][left] ~ m[up][right-1]
    for (int i = left; i < right; ++i) {
      result->push_back(matrix[up][i]);
    }
    // m[up+1][right-1] ~ m[down-1][right-1]
    for (int i = up + 1; i < down; ++i) {
      result->push_back(matrix[i][right - 1]);
    }
    // m[down-1][right-2] ~ m[down-1][left]
    if (down - 1 > up) {
      for (int i = right - 2; i >= left; --i) {
        result->push_back(matrix[down - 1][i]);
      }
    }
    // m[down-2][left] ~ m[up+1][left]
    if (left < right - 1) {
      for (int i = down - 2; i > up; --i) {
        result->push_back(matrix[i][left]);
      }
    }
  }
};
