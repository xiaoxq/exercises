#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> indexes;
    for (const string& str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      if (indexes.find(key) == indexes.end()) {
        indexes.insert({key, {str}});
      } else {
        indexes[key].push_back(str);
      }
    }

    vector<vector<string>> result;
    for (const auto& item : indexes) {
      result.push_back(item.second);
    }
    return result;
  }
};
