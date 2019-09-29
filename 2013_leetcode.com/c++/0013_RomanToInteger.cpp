#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    static const unordered_map<string, int> rtoi = {
        {"I", 1},    {"II", 2},    {"III", 3},    {"IV", 4},   {"V", 5},
        {"VI", 6},   {"VII", 7},   {"VIII", 8},   {"IX", 9},

        {"X", 10},   {"XX", 20},   {"XXX", 30},   {"XL", 40},  {"L", 50},
        {"LX", 60},  {"LXX", 70},  {"LXXX", 80},  {"XC", 90},

        {"C", 100},  {"CC", 200},  {"CCC", 300},  {"CD", 400}, {"D", 500},
        {"DC", 600}, {"DCC", 700}, {"DCCC", 800}, {"CM", 900},

        {"M", 1000}, {"MM", 2000}, {"MMM", 3000},
    };

    int ret = 0, start = 0;
    while (start < s.length()) {
      int end = start + 1;
      for (; end <= s.length(); ++end) {
        if (rtoi.find(s.substr(start, end - start)) != rtoi.end()) {
          continue;
        }
        ret += rtoi.find(s.substr(start, end - start - 1))->second;
        start = end - 1;
        break;
      }
      if (end > s.length()) {
        ret += rtoi.find(s.substr(start, end - start - 1))->second;
        break;
      }
    }
    return ret;
  }
};
