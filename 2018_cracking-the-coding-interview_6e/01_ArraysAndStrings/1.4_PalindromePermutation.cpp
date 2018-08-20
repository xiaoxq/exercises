#include <string>
#include <unordered_map>
using namespace std;

bool IsPalindromePermutation(const string& str) {
  unordered_map<char, int> char_count;
  for (const char ch : str) {
    if (isspace(ch)) {
      continue;
    }
    char ch_lower = tolower(ch);
    if (char_count.find(ch_lower) == char_count.end()) {
      char_count[ch_lower] = 1;
    } else {
      ++char_count[ch_lower];
    }
  }

  int odd_quota = 1;
  for (const auto& entry : char_count) {
    if (entry.second % 2 == 1) {
      if (--odd_quota < 0) {
        return false;
      }
    }
  }
  return true;
}

///////////////// TEST /////////////////
#include <iostream>
#include <vector>

int main() {
	const vector<string> test_cases = {
      "",
      "a",
			"Tact Coa",
			"Tact Coa o",
			"Tact Coa b"
	};

	for (const string& test_case : test_cases) {
		cout << "IsPalindromePermutation(" << test_case << ") = "
         << IsPalindromePermutation(test_case) << endl;
	}

	return 0;
}
