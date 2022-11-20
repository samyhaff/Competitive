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
    int getLength(ListNode *head) {
        if (!head) return 0;
        return 1 + getLength(head->next);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head);
        int index = length - n;
        ListNode *curr = head;

        if (length == 1) return nullptr;
        if (index == 0) return head->next;

        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        curr->next = curr->next->next;

        return head;
    }
};
