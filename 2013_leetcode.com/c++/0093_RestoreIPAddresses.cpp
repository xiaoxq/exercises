/*
 * Problem: http://leetcode.com/onlinejudge#question_93
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    restoreIpAddresses(s, 0, 4, "", &result);
    return result;
  }

 private:
  void restoreIpAddresses(const string& s, int index, int remain_parts,
                          const string& prefix, vector<string>* result) {
    // Reach the end.
    if (remain_parts == 1) {
      string last_part;
      if (readPart(s, index, s.length() - index, &last_part)) {
        result->push_back(prefix + last_part);
      }
      return;
    }

    string next_part;
    for (int len = 1; len <= 3; ++len) {
      if (readPart(s, index, len, &next_part)) {
        string new_prefix = prefix + next_part + ".";
        restoreIpAddresses(s, index + len, remain_parts - 1, new_prefix,
                           result);
      } else {
        break;
      }
    }
  }

  bool readPart(const string& s, int index, int len, string* part) {
    if (len < 1 || index + len > s.length()) {
      return false;
    }
    *part = s.substr(index, len);
    return isPartValid(*part);
  }

  bool isPartValid(const std::string& part) {
    const int value = atoi(part.c_str());
    return (part.length() == 1) || (part.length() == 2 && part[0] != '0') ||
           (part.length() == 3 && value >= 100 && value <= 255);
  }
};
