#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> leftBrackets;
    for (const char ch : s) {
      switch (ch) {
      case '(':
      case '[':
      case '{':
        leftBrackets.push(ch);
        break;
      case ')':
        if (leftBrackets.empty() || leftBrackets.top() != '(') {
          return false;
        }
        leftBrackets.pop();
        break;
      case ']':
        if (leftBrackets.empty() || leftBrackets.top() != '[') {
          return false;
        }
        leftBrackets.pop();
        break;
      case '}':
        if (leftBrackets.empty() || leftBrackets.top() != '{') {
          return false;
        }
        leftBrackets.pop();
        break;
      }
    }
    return leftBrackets.empty();
  }
};
