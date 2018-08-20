#include <string>
using namespace std;

string StringCompression(const string& str) {
  if (str.empty()) {
    return str;
  }

  string result;
  int count = 1;
  for (int i = 1; i < str.length(); ++i) {
    if (str[i] == str[i - 1]) {
      ++count;
    } else {
      result.append({str[i - 1]});
      result.append(to_string(count));
      count = 1;
    }
  }
  result.append({str.back()});
  result.append(to_string(count));
  return result.length() < str.length() ? result : str;
}

///////////////// TEST /////////////////
#include <iostream>
#include <vector>

int main() {
	const vector<string> test_cases = {
      "aabcccccaaa"
	};

	for (const string& test_case : test_cases) {
		cout << "StringCompression(" << test_case << ") = "
         << StringCompression(test_case) << endl;
	}

	return 0;
}
