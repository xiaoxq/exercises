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
      return head;
    }
    ListNode* w = head;
    ListNode* w_pre = nullptr;
    ListNode* r = head->next;
    bool w_duplicated = false;
    while (r != nullptr) {
      if (r->val == w->val) {
        w_duplicated = true;
      } else {
        // Found a new value.
        if (!w_duplicated) {
          // Save current w.
          w_pre = w;
          w->next = r;
          w = r;
        } else {
          // Reset w.
          w->val = r->val;
        }
        w_duplicated = false;
      }
      r = r->next;
    }
    if (w_duplicated) {
      // Remove current w.
      if (w_pre == nullptr) {
        return nullptr;
      }
      w_pre->next = nullptr;
    } else {
      w->next = nullptr;
    }
    return head;
  }
};
