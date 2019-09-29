#include <climits>

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    return isValidBST(root, INT_MIN, false, INT_MAX, false);
  }

 private:
  bool isValidBST(TreeNode *root, int min, bool min_included, int max,
                  bool max_included) {
    if (root == nullptr) {
      return true;
    }
    if (root->val < min || (min_included && root->val == min)) {
      return false;
    }
    if (root->val > max || (max_included && root->val == max)) {
      return false;
    }
    return isValidBST(root->left, min, min_included, root->val, true) &&
           isValidBST(root->right, root->val, true, max, max_included);
  }
};
