#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    if (nums.size() == 1) {
      return 0;
    }
    // reach lBound in result jumps, reach rBound in result+1 jumps
    int result=1, lBound=1, rBound=nums[0];
    while (rBound + 1 < nums.size()) {
      ++result;

      int newRBound = 0;
      for (int i = lBound; i <= rBound; ++i) {
        newRBound = max(newRBound, i + nums[i]);
      }

      lBound = rBound + 1;
      rBound = newRBound;
    }
    return result;
  }
};
