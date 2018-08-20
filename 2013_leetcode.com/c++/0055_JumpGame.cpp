#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.size() == 1) {
      return true;
    }

    // reach [lBound,rBound) in the same steps
    int lBound = 1, rBound = nums[0] + 1;
    while (rBound < nums.size() && lBound < rBound) {
      int newRBound = 0;
      for (int i = lBound; i < rBound; ++i) {
        newRBound = max(newRBound, i + nums[i]);
      }
      lBound = rBound;
      rBound = newRBound + 1;
    }
    return rBound >= nums.size();
  }
};
