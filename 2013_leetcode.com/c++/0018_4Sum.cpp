#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (nums.empty()) {
      return result;
    }

    sort(nums.begin(), nums.end());
    for (int index1 = 0; index1 + 3 < nums.size(); ++index1) {
      while (index1 > 0 && index1 + 3 < nums.size() &&
             nums[index1] == nums[index1 - 1]) {
        ++index1;
      }
      for (int index2 = index1 + 1; index2 + 2 < nums.size(); ++index2) {
        while (index2 > index1 + 1 && index2 + 2 < nums.size() &&
               nums[index2] == nums[index2 - 1]) {
          ++index2;
        }
        int index3 = index2 + 1, index4 = nums.size() - 1;
        while (index3 < index4) {
          while (index3 > index2 + 1 && index3 < index4 &&
                 nums[index3] == nums[index3 - 1]) {
            ++index3;
          }
          if (index3 >= index4) {
            break;
          }

          const int sum =
              nums[index1] + nums[index2] + nums[index3] + nums[index4];
          if (sum == target) {
            result.push_back(
                {nums[index1], nums[index2], nums[index3], nums[index4]});
            ++index3;
            --index4;
          } else if (sum > target) {
            --index4;
          } else {
            ++index3;
          }
        }
      }
    }
    return result;
  }
};
