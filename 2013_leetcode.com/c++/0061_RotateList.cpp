// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) {
      return nullptr;
    }

    int len = 1;
    ListNode* tail = head;
    while (tail->next != nullptr) {
      ++len;
      tail = tail->next;
    }
    tail->next = head;

    len = len - (k % len);
    while (--len) {
      head = head->next;
    }

    tail = head;
    head = head->next;
    tail->next = nullptr;
    return head;
  }
};
