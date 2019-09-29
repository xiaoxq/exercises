// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* tail = head;
    while (tail->next != nullptr) {
      if (tail->next->val != tail->val) {
        tail = tail->next;
      } else {
        tail->next = tail->next->next;
      }
    }
    return head;
  }
};
