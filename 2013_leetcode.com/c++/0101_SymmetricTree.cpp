#include <queue>
using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    queue<TreeNode *> leftToRight;
    queue<TreeNode *> rightToLeft;
    leftToRight.push(root->left);
    rightToLeft.push(root->right);
    while (!leftToRight.empty()) {
      TreeNode *leftNode = leftToRight.front();
      leftToRight.pop();
      TreeNode *rightNode = rightToLeft.front();
      rightToLeft.pop();
      // the same, such as both nullptr
      if (leftNode == rightNode) {
        continue;
      }
      if (leftNode == nullptr || rightNode == nullptr ||
          leftNode->val != rightNode->val) {
        return false;
      }
      leftToRight.push(leftNode->left);
      leftToRight.push(leftNode->right);
      rightToLeft.push(rightNode->right);
      rightToLeft.push(rightNode->left);
    }
    return true;
  }
};
