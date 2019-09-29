#include <string>
#include <vector>
using namespace std;

const int kBoardSize = 9;

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    // Build candidates set for each row, col and rect.
    vector<vector<bool>> row(
        kBoardSize, {true, true, true, true, true, true, true, true, true});
    vector<vector<bool>> col = row;
    vector<vector<bool>> rect = row;
    vector<vector<int>> to_fill;
    for (int i = 0; i < kBoardSize; ++i) {
      for (int j = 0; j < kBoardSize; ++j) {
        if (board[i][j] != '.') {
          row[i][board[i][j] - '1'] = false;
          col[j][board[i][j] - '1'] = false;
          rect[ijToRect(i, j)][board[i][j] - '1'] = false;
        } else {
          to_fill.push_back({i, j});
        }
      }
    }

    fillCells(to_fill, 0, &board, &row, &col, &rect);
  }

 private:
  inline int ijToRect(int i, int j) { return i / 3 * 3 + j / 3; }

  bool fillCells(const vector<vector<int>>& to_fill, const int index,
                 vector<vector<char>>* board, vector<vector<bool>>* row,
                 vector<vector<bool>>* col, vector<vector<bool>>* rect) {
    // Fully filled.
    if (to_fill.size() == index) {
      return true;
    }
    const int i = to_fill[index][0];
    const int j = to_fill[index][1];
    auto& my_row = row->at(i);
    auto& my_col = col->at(j);
    auto& my_rect = rect->at(ijToRect(i, j));

    for (int k = 0; k < kBoardSize; ++k) {
      if (my_row[k] && my_col[k] && my_rect[k]) {
        my_row[k] = my_col[k] = my_rect[k] = false;
        if (fillCells(to_fill, index + 1, board, row, col, rect)) {
          board->at(i)[j] = '1' + k;
          return true;
        }
        my_row[k] = my_col[k] = my_rect[k] = true;
      }
    }
    return false;
  }
};
