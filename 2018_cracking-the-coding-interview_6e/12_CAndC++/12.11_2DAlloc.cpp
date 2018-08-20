#include <cstddef>
using namespace std;

template <class T>
T** My2DAlloc(const size_t rows, const size_t cols) {
  T** arr = new T*[rows];
  T* mem = new T[rows * cols];
  for (int i = 0; i < rows; ++i) {
    arr[i] = &mem[i * cols];
  }
  return arr;
}

template <class T>
void My2DDealloc(T** arr, const size_t rows, const size_t cols) {
  delete [] arr[0];
  delete [] arr;
}

///////////////// TEST /////////////////
#include <iostream>

int main() {
  {
    int** arr = My2DAlloc<int>(1, 1);
    arr[0][0] = 1;
    cout << arr[0][0] << endl;
    My2DDealloc(arr, 1, 1);
  }

  {
    int** arr = My2DAlloc<int>(2, 2);
    arr[0][0] = 0;
    arr[0][1] = 1;
    arr[1][0] = 2;
    arr[1][1] = 3;
    cout << arr[0][0] << arr[0][1] << arr[0][2] << arr[0][3] << endl;
    My2DDealloc(arr, 2, 2);
  }

  return 0;
}
