#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> result = {0};
    unordered_set<int> used = {0};

    int current = 0;
    int last_current = -1;
    while (last_current != current) {
      last_current = current;
      for (int i = 0; i < n; ++i) {
        const int changeOneBit = current ^ (1 << i);
        if (used.insert(changeOneBit).second) {
          current = changeOneBit;
          result.push_back(current);
          break;
        }
      }
    }
    return result;
  }
};
