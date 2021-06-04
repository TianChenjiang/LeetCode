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
        unordered_set<ListNode*> st;
        ListNode* curA = headA, *curB = headB;
        while (curA != NULL) {
            st.insert(curA);
            curA = curA->next;
        }
        while (curB != NULL) {
            if (st.find(curB) != st.end()) return curB;
            curB = curB->next;
        }
        return NULL;
    }
};