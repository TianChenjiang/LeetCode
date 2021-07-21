/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* cur1 = headA, *cur2 = headB;
        while (cur1 != cur2) {
            if (cur1) cur1 = cur1->next;
            else cur1 = headB;
            if (cur2) cur2 = cur2->next;
            else cur2 = headA;
        }
        return cur1;
    }
};