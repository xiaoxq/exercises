#include <string>
using namespace std;

void Swap(string& str, int i, int j) {
  if (i != j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

// Return str[left, right] sorted.
bool QuickSort(string& str, int left, int right) {
  if (left >= right) {
    return true;
  }
  int l = left + 1, r = right, pivot = left;
  while (l <= r) {
    if (str[l] == str[pivot] || str[r] == str[pivot]) {
      return false;
    }
    if (str[l] < str[pivot]) {
      ++l;
    } else {
      Swap(str, l, r--);
    }
  }
  Swap(str, r, pivot);
  return QuickSort(str, left, r - 1) && QuickSort(str, r + 1, right);
}

bool IsUnique(string str) {
  return str.empty() || QuickSort(str, 0, str.length() - 1);
}

///////////////// TEST /////////////////
#include <iostream>
#include <vector>

int main() {
  const vector<string> test_cases = {
       "",
      "a",
      "abcdef",
      "abcdefa",
      "aaaaaa"
  };

  for (const string& test_case : test_cases) {
    const bool is_uniq = IsUnique(test_case);
    cout << "IsUnique(" << test_case << ") = " << is_uniq << endl;
  }
  return 0;
}
