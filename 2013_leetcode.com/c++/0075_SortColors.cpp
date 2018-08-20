#include <vector>
using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int writeRed = 0, writeBlue = nums.size() - 1;
    for (int r = 0; r <= writeBlue;) {
      switch(nums[r]) {
        case RED:
          swap(nums, writeRed, r);
          ++writeRed;
          ++r;
          break;
        case WHITE:
          ++r;
          break;
        case BLUE:
          swap(nums, writeBlue, r);
          --writeBlue;
          break;
      }
    }
  }

 private:
  enum Color {
    RED = 0,
    WHITE = 1,
    BLUE = 2
  };

  inline void swap(vector<int>& nums, const int i, const int j) {
    if (nums[i] != nums[j]) {
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }
  }
};
