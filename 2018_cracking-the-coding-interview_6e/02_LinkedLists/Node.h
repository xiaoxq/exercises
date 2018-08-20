#include <iostream>

struct Node {
  Node(int data = 0, Node* next = nullptr) {
    this->data = data;
    this->next = next;
  }

  static void Print(Node* head) {
    if (head == nullptr) {
      std::cout << "NULL";
    } else {
      while (head) {
        std::cout << head->data;
        if (head->next) {
          std::cout << "->";
        }
        head = head->next;
      }
    }
  }

  int data;
  Node* next;
};
