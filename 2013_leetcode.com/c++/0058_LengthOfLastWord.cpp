
#include <string>
using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    const auto last_char = s.find_last_not_of(' ');
    if (last_char == string::npos) {
      return 0;
    }

    const auto last_space = s.find_last_of(' ', last_char);
    return last_space != string::npos ? last_char - last_space : last_char + 1;
  }
};
