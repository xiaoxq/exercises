// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *head = nullptr, *tail = nullptr;
    while (l1 != nullptr && l2 != nullptr) {
      ListNode *next;
      if (l1->val < l2->val) {
        next = l1;
        l1 = l1->next;
      } else {
        next = l2;
        l2 = l2->next;
      }

      if (tail == nullptr) {
        head = tail = next;
      } else {
        tail->next = next;
        tail = next;
      }
    }
    if (tail != nullptr) {
      tail->next = (l1 == nullptr) ? l2 : l1;
    } else {
      head = (l1 == nullptr) ? l2 : l1;
    }
    return head;
  }
};
