#include <vector>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.empty()) {
      return 0;
    }

    int result = 0;
    int left = 0, right = height.size() - 1;
    // left, right are current max height
    while (left < right) {
      if (height[left] < height[right]) {
        // move left forward
        int i = left + 1;
        for (; i < right && height[i] <= height[left]; ++i) {
          result += height[left] - height[i];
        }
        left = i;
      } else {
        // move right forward
        int i = right - 1;
        for (; i > left && height[i] <= height[right]; --i) {
          result += height[right] - height[i];
        }
        right = i;
      }
    }
    return result;
  }
};
