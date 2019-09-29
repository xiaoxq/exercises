// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // the same node or both nullptr
    if (p == q) {
      return true;
    }
    // only one is nullptr, or not equal
    if (p == nullptr || q == nullptr || p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
