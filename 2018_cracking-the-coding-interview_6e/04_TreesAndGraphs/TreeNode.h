#include <iostream>

struct TreeNode {
  TreeNode(int data = 0, Node* left = nullptr, Node* right = nullptr) {
    this->data = data;
    this->left = left;
    this->right = right;
  }

  int data;
  TreeNode* left;
  TreeNode* right;
};
