/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, val1 = 0, val2 = 0;
        ListNode *res = new ListNode;
        ListNode *current = res;

        val1 = l1->val; val2 = l2->val;
        l1 = l1->next; l2 = l2->next;
        current->next = nullptr;
        current->val = (val1 + val2) % 10;
        carry = (val1 + val2) / 10;

        while (carry || l1 || l2) {
            current->next = new ListNode;
            current->next->next = nullptr;
            val1 = val2 = 0;

            if (l1) {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val2 = l2->val;
                l2 = l2->next;
            }

            current->next->val = (carry + val1 + val2) % 10;
            carry = (carry + val1 + val2) / 10;

            current = current->next;
        }

        return res;
    }
};
