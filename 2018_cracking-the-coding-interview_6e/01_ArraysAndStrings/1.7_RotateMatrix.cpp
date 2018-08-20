#include <vector>
using namespace std;

// NxN matrix.
void RotateMatrix(vector<vector<int>>& matrix) {
  if (matrix.empty() || matrix.size() != matrix[0].size()) {
    return;
  }
  const int N = matrix.size();
	for (int i = 0; i < (N + 1) / 2; ++i) {
		for (int j = 0; j < N / 2; ++j) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[N - j - 1][i];
			matrix[N - j - 1][i] = matrix[N - i - 1][N - j - 1];
			matrix[N - i - 1][N - j - 1] = matrix[j][N - i - 1];
			matrix[j][N - i - 1] = temp;
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
	cout << "=================" << endl << "RotateMatrix(" << endl;
	PrintMatrix(writable);
	cout << ")=" << endl;
	RotateMatrix(writable);
	PrintMatrix(writable);
}

int main() {
  Test({});

	Test({
			{1},
	});

	Test({
			{1, 2,},
			{3, 4,},
	});

	Test({
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
	});

	return 0;
}
