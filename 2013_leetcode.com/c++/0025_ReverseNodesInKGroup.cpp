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
  ListNode* reverseKGroup(ListNode* head, int k) {
    unique_ptr<ListNode> pre_head(new ListNode(0));
    pre_head->next = head;

    ListNode* pre_swap = pre_head.get();
    while (pre_swap) {
      // Check group
      ListNode* tail = pre_swap;
      for (int i = 0; i < k && tail != nullptr; ++i) {
        tail = tail->next;
      }
      if (tail == nullptr) {
        break;
      }

      ListNode* global_next = tail->next;

      ListNode* pre = pre_swap->next;
      ListNode* cur = pre->next;
      for (int i = 0; i + 1 < k; ++i) {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
      pre_swap->next->next = global_next;
      ListNode* next = pre_swap->next;
      pre_swap->next = tail;
      pre_swap = next;
    }
    return pre_head->next;
  }
};
