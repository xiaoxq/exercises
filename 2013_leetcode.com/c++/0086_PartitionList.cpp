#include <memory>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    unique_ptr<ListNode> smaller_head(new ListNode(0));
    unique_ptr<ListNode> greater_head(new ListNode(0));
    ListNode* smaller_tail = smaller_head.get();
    ListNode* greater_tail = greater_head.get();
    while (head != nullptr) {
      if (head->val < x) {
        smaller_tail->next = head;
        smaller_tail = head;
      } else {
        greater_tail->next = head;
        greater_tail = head;
      }
      head = head->next;
    }
    smaller_tail->next = greater_head->next;
    greater_tail->next = nullptr;
    return smaller_head->next;
  }
};
