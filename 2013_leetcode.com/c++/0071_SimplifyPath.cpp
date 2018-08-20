#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> pathes;
    size_t start = 0;
    while (start < path.length()) {
      start = path.find_first_not_of('/', start);
      if (start == string::npos) {
        break;
      }
      // CHECK(start != string::npos)
      const auto end = path.find_first_of('/', start);
      const string sub_path = path.substr(start, end - start);
      if (sub_path == ".") {
        // Nothing to do.
      } else if (sub_path == "..") {
        if (!pathes.empty()) {
          pathes.pop_back();
        }
      } else {
        pathes.push_back(sub_path);
      }
      start = end;
    }

    string result;
    if (pathes.empty()) {
      result.append(1, '/');
    }
    for (const string& sub_path : pathes) {
      result.append(1, '/');
      result.append(sub_path);
    }
    return result;
  }
};
