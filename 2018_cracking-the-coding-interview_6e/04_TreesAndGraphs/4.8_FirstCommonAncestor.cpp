#include <string>

#include "TreeNode.h"

using namespace std;

// Return node:
// nullptr if neigher n1 nor n2 were found.
// n1 if found n1.
// n2 if found n2.
// result if both n1 and n2 were found.
Node* FindNodes(TreeNode* sub_root, TreeNode* n1, TreeNode* n2) {
  if (sub_root == nullptr) {
    return nullptr;
  }
  Node* left = FindNodes(sub_root->left, n1, n2);
  Node* right = FindNodes(sub_root->right, n1, n2);
  // Found two nodes at left.
  if (left != nullptr && left != n1 && left != n2) {
    return left;
  }
  // Found two nodes at right.
  if (right != nullptr && right != n1 && right != n2) {
    return right;
  }
  // Found one node at left.
  if (left == n1 || left == n2) {
    // Found the other at current node or right subtree.
    if (right == n1 || right == n2 || sub_root == n1 || sub_root == n2) {
      return sub_root;
    }
    return left;
  }
  // Found one node at right.
  if (right == n1 || right == n2) {
    if (sub_root == n1 || sub_root == n2) {
      return sub_root;
    }
    return right;
  }
  // Cannot find any nodes in subtrees.
  if (sub_root == n1 || sub_root == n2) {
    return sub_root;
  }
  return nullptr;
}

Node* FirstCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
  Node* result = FindNodes(root, n1, n2);
  // Only one node was found.
  if (n1 != n2 && (result == n1 || result == n2)) {
    return nullptr;
  }
  return result;
}
