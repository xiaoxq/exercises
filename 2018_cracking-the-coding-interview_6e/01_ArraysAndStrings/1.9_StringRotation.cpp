#include <string>
using namespace std;

bool isRotation(const string& str1, const string& str2) {
  if (str1.length() != str2.length()) {
    return false;
  }
  string double_str1 = str1 + str1;
  return double_str1.find(str2) != string::npos;
}

///////////////// TEST /////////////////
#include <iostream>
#include <vector>

int main() {
  const vector<string> test_cases = {
      "", "a",
      "", "",
      "abc", "abcd",
      "abc", "abc",
      "abc", "cab",
      "abc", "bca",
  };

  for (int i = 0; i < test_cases.size(); i += 2) {
    cout << "isRotation(" << test_cases[i] << ", " << test_cases[i + 1] << ") = "
         << isRotation(test_cases[i], test_cases[i + 1]) << endl;
  }

  return 0;
}
