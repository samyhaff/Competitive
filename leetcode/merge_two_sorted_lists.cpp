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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode *head;
        if (list1->val < list2->val) {
            head = list1;
            head->next = mergeTwoLists(list1->next, list2);
            return head;
        } else {
            head = list2;
            head->next = mergeTwoLists(list1, list2->next);
            return head;
        }
    }
};
