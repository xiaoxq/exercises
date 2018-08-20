// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode *head, int n) {
    ListNode* tail = head;
    for (int i = 0; i < n; ++i) {
      tail = tail->next;
    }
    // remove the head
    if (tail == nullptr) {
      return head->next;
    }

    ListNode *pre = head;
    while (tail->next != nullptr) {
      tail = tail->next;
      pre = pre->next;
    }

    pre->next = pre->next->next;
    return head;
  }
};
