#include <string>
using namespace std;

bool IsTheSame(const string& str1, const size_t pos1,
               const string& str2, const size_t pos2) {
  if (str1.length() - pos1 != str2.length() - pos2) {
    return false;
  }
  if (pos1 >= str1.length()) {
    return true;
  }
  return 0 == str1.compare(pos1, str1.length() - pos1,
                           str2, pos2, str2.length() - pos2);
}

bool IsOneAway(const string& str1, const string& str2) {
  const size_t diff_len = str1.length() > str2.length() ?
      str1.length() - str2.length() : str2.length() - str1.length();
  if (diff_len > 1) {
    return false;
  }

  size_t i = 0;
  for (; i < str1.length() && i < str2.length(); ++i) {
    if (str1[i] != str2[i]) {
      break;
    }
  }
  return IsTheSame(str1, i + 1, str2, i) ||
         IsTheSame(str1, i, str2, i + 1) || 
         IsTheSame(str1, i + 1, str2, i + 1);
}

///////////////// TEST /////////////////
#include <iostream>
#include <vector>

int main() {
	const vector<string> test_cases = {
      "", "",
      "", " ",
      "", " a",
      "a", " a",
      "pale", "ple",
      "pales", "pale",
      "pale", "bale",
      "pale", "bake"
	};

	for (int i = 0; i < test_cases.size(); i += 2) {
		cout << "IsOneAway(" << test_cases[i] << ", " << test_cases[i + 1] << ") = "
         << IsOneAway(test_cases[i], test_cases[i + 1]) << endl;
	}

	return 0;
}
