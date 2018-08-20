#include <string>
using namespace std;

void URLify(string& str) {
  int w = str.length() - 1;

  bool skip_trail = true;
  for (int r = str.length() - 1; r >= 0; --r) {
    if (str[r] != ' ') {
      skip_trail = false;
      str[w--] = str[r];
    } else if (!skip_trail) {
      str[w--] = '0';
      str[w--] = '2';
      str[w--] = '%';
    }
  }
}

///////////////// TEST /////////////////
#include <iostream>
#include <vector>

int main() {
	const vector<string> test_cases = {
			"",
			" ",
			"abc",
			" abc  ",
			"abc ",
			"abc abc  ",
			"abc  abc    ",
	};

	for (const string& test_case : test_cases) {
    string to_modify = test_case;
    URLify(to_modify);
		cout << "URLify(" << test_case << ") = " << to_modify << endl;
	}

	return 0;
}
