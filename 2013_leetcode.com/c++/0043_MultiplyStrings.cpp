#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    vector<string> components;
    for (int i = 0; i < num2.length(); ++i) {
      components.push_back(multiply(num1, num2[i], num2.length() - i - 1));
    }
    string result;
    int remain = 0;
    const int max_len = components.front().length();
    for (int i = 0; i < max_len; ++i) {
      for (const string& comp : components) {
        if (i < comp.length()) {
          remain += comp[i] - '0';
        }
      }
      result += '0' + (remain % 10);
      remain /= 10;
    }
    while (remain > 0) {
      result += '0' + (remain % 10);
      remain /= 10;
    }
    while (result.length() > 1 && result.back() == '0') {
      result.pop_back();
    }
    return string(result.rbegin(), result.rend());
  }

 private:
  // 0 <= num2 <= 9
  string multiply(const string& num1, const char num2, const int rank) {
    if (num2 == '0') {
      return "0";
    }
    const int int2 = num2 - '0';
    string result(rank, '0');
    int remain = 0;
    for (auto iter = num1.rbegin(); iter != num1.rend(); ++iter) {
      remain += (*iter - '0') * int2;
      result += '0' + (remain % 10);
      remain /= 10;
    }
    if (remain > 0) {
      result += '0' + remain;
    }
    return result;
  }
};
