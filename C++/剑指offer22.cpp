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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head, *slow = head;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast != NULL) {
            fast = fast->next;
            // if (fast == NULL) return slow;
            slow = slow->next;
        }
        return slow;
    }
};