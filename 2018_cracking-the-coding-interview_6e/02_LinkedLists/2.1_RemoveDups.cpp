#include <string>

#include "Node.h"

using namespace std;

void RemoveDups(Node* head) {
  if (head == nullptr) {
    return;
  }
  Node* pre = head;
  while (pre->next) {
    bool has_dup = false;
    for (Node* p = head; p != pre->next; p = p->next) {
      if (p->data == pre->next->data) {
        has_dup = true;
        break;
      }
    }
    if (has_dup) {
      // Skip next.
      pre->next = pre->next->next;
    } else {
      pre = pre->next;
    }
  }
}

///////////////// TEST /////////////////
#include <iostream>

void Test(Node* head) {
  cout << "RemoveDups(";
  Node::Print(head);
  cout << ") = ";
  RemoveDups(head);
  Node::Print(head);
  cout << endl;
}

int main() {
  Test(nullptr);

  Node* test_case0 = new Node(0, nullptr);
  Test(test_case0);
  delete test_case0;

  Node* test_case1[3];
  test_case1[2] = new Node(2, nullptr);
  test_case1[1] = new Node(1, test_case1[2]);
  test_case1[0] = new Node(0, test_case1[1]);
  Test(test_case1[0]);
  delete test_case1[0];
  delete test_case1[1];
  delete test_case1[2];

  Node* test_case2[3];
  test_case2[2] = new Node(1, nullptr);
  test_case2[1] = new Node(1, test_case2[2]);
  test_case2[0] = new Node(0, test_case2[1]);
  Test(test_case2[0]);
  delete test_case2[0];
  delete test_case2[1];
  delete test_case2[2];

  Node* test_case3[3];
  test_case3[2] = new Node(0, nullptr);
  test_case3[1] = new Node(1, test_case3[2]);
  test_case3[0] = new Node(0, test_case3[1]);
  Test(test_case3[0]);
  delete test_case3[0];
  delete test_case3[1];
  delete test_case3[2];

  return 0;
}
