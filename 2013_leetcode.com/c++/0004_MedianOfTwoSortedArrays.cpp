#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int median = (nums1.size() + nums2.size()) / 2;
    double result = findKthInRange(nums1, nums2, median + 1);
    if ((nums1.size() + nums2.size()) % 2 == 0) {
      result += findKthInRange(nums1, nums2, median);
      result /= 2;
    }
    return result;
  }

private:
  int findKthInRange(const vector<int>& nums1, const vector<int>& nums2,
                     int k ) {
    int leftA = 0, rightA = nums1.size();
    int leftB = 0, rightB = nums2.size();

    while (leftA < rightA && leftB < rightB && k > 1) {
      const int middleA = (leftA + rightA) / 2;
      const int middleB = (leftB + rightB) / 2;

      // section 1: A[leftA,middleA] // section 2: A(middleA, rightA)
      // section 3: B[leftB,middleB) // section 4: B[middleB, rightB)
      if (nums1[middleA] <= nums2[middleB]) {
        if (middleA - leftA + 1 + middleB - leftB >= k) {
          // throw section 4
          rightB = middleB;
        } else {
          // throw section 1
          k -= middleA - leftA + 1;
          leftA = middleA + 1;
        }
      } else {
        // section 1: A[leftA,middleA) // section 2: A[middleA, rightA)
        // section 3: B[leftB,middleB] // section 4: B(middleB, rightB)

        // throw section 2
        if (middleA - leftA + 1 + middleB - leftB >= k ) {
          rightA = middleA;
        } else {
          // throw section 3
          k -= middleB - leftB + 1;
          leftB = middleB + 1;
        }
      }
    }

    // when reach here, leftA==rightA || leftB==rightB || k==1
    int result = 0;
    if (leftA == rightA) {
      result = nums2[leftB + k - 1];
    } else if (leftB == rightB) {
      result = nums1[leftA + k - 1];
    } else if (k == 1) {
      result = min(nums1[leftA], nums2[leftB]);
    }

    return result;
  }
};
