// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr, *tail = nullptr;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr) {
      int num1 = (l1 != nullptr) ? l1->val : 0;
      int num2 = (l2 != nullptr) ? l2->val : 0;
      int sum = num1 + num2 + carry;
      carry = sum / 10;
      sum %= 10;

      if (tail == nullptr) {
        // initial
        head = tail = new ListNode(sum);
      } else {
        // generally
        tail->next = new ListNode(sum);
        tail = tail->next;
      }

      if (l1 != nullptr) {
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        l2 = l2->next;
      }
    }

    // the final carry
    if(carry > 0) {
      tail->next = new ListNode(carry);
    }

    return head;
  }
};
