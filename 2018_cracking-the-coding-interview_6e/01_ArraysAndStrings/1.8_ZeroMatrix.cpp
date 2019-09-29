#include <vector>
using namespace std;

// With constant memory.
void ZeroMatrix(vector<vector<int>>& matrix) {
  if (matrix.empty() || matrix[0].empty()) {
    return;
  }

  bool clear_row0 = false, clear_col0 = false;
  for (const auto col : matrix[0]) {
    if (col == 0) {
      clear_row0 = true;
      break;
    }
  }
  for (const auto& row : matrix) {
    if (row[0] == 0) {
      clear_col0 = true;
      break;
    }
  }

  for (int i = 1; i < matrix.size(); ++i) {
    for (int j = 1; j < matrix[0].size(); ++j) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = matrix[0][j] = 0;
      }
    }
  }

  for (int i = 1; i < matrix.size(); ++i) {
    if (matrix[i][0] == 0) {
      for (int j = 1; j < matrix[0].size(); ++j) {
        matrix[i][j] = 0;
      }
    }
  }

  for (int j = 1; j < matrix[0].size(); ++j) {
    if (matrix[0][j] == 0) {
      for (int i = 1; i < matrix.size(); ++i) {
        matrix[i][j] = 0;
      }
    }
  }
  if (clear_row0) {
    for (int j = 0; j < matrix[0].size(); ++j) {
      matrix[0][j] = 0;
    }
  }
  if (clear_col0) {
    for (int i = 0; i < matrix.size(); ++i) {
      matrix[i][0] = 0;
    }
  }
}

///////////////// TEST /////////////////
#include <iostream>

void PrintMatrix(const vector<vector<int>>& matrix) {
  for (const auto& row : matrix) {
    for (const auto elem : row) {
      cout << elem << " ";
    }
    cout << endl;
  }
}

void Test(const vector<vector<int>>& matrix) {
  auto writable = matrix;
  cout << "=================" << endl << "ZeroMatrix(" << endl;
  PrintMatrix(writable);
  cout << ")=" << endl;
  ZeroMatrix(writable);
  PrintMatrix(writable);
}

int main() {
  Test({});

  Test({
      {0},
  });

  Test({
      {1},
  });

  Test({
      {1, 2},
      {3, 4},
  });

  Test({
      {0, 1},
      {2, 3},
  });

  Test({
      {0, 1, 2},
      {3, 4, 0},
      {5, 6, 7},
  });

  Test({
      {1, 2, 3},
      {4, 0, 5},
      {6, 7, 8},
  });

  return 0;
}
