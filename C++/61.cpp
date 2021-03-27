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
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 0;
        ListNode* cur = head, *former = head, *latter = head;
        while (cur) {
            cur = cur->next;
            size++;
        }
        if (size == 0) return head;
        k %= size;
        if (k == 0) return head;
        for (int i = 0; i < k; i++) former = former->next;
        while (former->next) {
            former = former->next;
            latter = latter->next;
        }
        ListNode* res = latter->next;
        former->next = head;
        latter->next = nullptr;
        return res;
    }
};