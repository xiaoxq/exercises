#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int max_area = 0;
    int x1 = 0, x2 = height.size() - 1;
    while (x1 < x2) {
      const int area = (x2 - x1) * min(height[x1], height[x2]);
      max_area = max(max_area, area);
      height[x1] < height[x2] ? ++x1 : --x2;
    }
    return max_area;
  }
};
