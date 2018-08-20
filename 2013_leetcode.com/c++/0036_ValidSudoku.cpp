#include <vector>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    static const int kBoardSize = 9;
    for (int row = 0; row < kBoardSize; ++row) {
      for (int col = 0; col < kBoardSize; ++col) {
        if( board[row][col]=='.' ) {
          continue;
        }

        // check right side
        for (int i = col + 1; i < kBoardSize; ++i) {
          if (board[row][i] == board[row][col]) {
            return false;
          }
        }

        // check lower side
        for (int i = row + 1; i < kBoardSize; ++i) {
          if (board[i][col] == board[row][col]) {
            return false;
          }
        }

        // check 3x3
        const int rowLimit = row / 3 * 3 + 3;
        const int colLimit = col / 3 * 3 + 3;
        for (int i = row; i < rowLimit; ++i) {
          for (int j = colLimit - 3; j < colLimit; ++j) {
            if (row == i && col == j) {
              continue;
            }
            if (board[i][j] == board[row][col]) {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
};
