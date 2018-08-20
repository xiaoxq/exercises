#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// This solution will cause exceeding time limit, but should be enough for an
// interview. Hashtable is efficient but create new dict and substrings are
// time consuming.
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> dict;
    for (const string& word : words) {
      if (dict.find(word) == dict.end()) {
        dict[word] = 1;
      } else {
        ++dict[word];
      }
    }

    vector<int> result;
    if (words.empty() || words[0].empty()) {
      return result;
    }

    for (int i = 0; i < s.length(); ++i) {
      if (match(s, i, dict, words.size(), words[0].length())) {
        result.push_back(i);
      }
    }
    return result;
  }

 private:
  bool match(const string& s, const int index,
             const unordered_map<string, int>& dict,
             const int word_count, const int word_len) {
    unordered_map<string, int> local_dict = dict;
    for (int i = 0; i < word_count; ++i) {
      const string sub = s.substr(index + i * word_len, word_len);
      if (local_dict.find(sub) == dict.end() || local_dict[sub] == 0) {
        return false;
      }
      --local_dict[sub];
    }
    return true;
  }
};
