package LinkedList; /**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

/**
 * Definition for singly-linked list.
 * public class LinkedList.ListNode {
 *     int val;
 *     LinkedList.ListNode next;
 *     LinkedList.ListNode(int x) { val = x; }
 * }
 */



class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode result = head;
        int carry = 0;
        int x1,x2;
        int current;
        while (l1 != null || l2 != null || carry != 0) {
            if(l1 == null) {
                x1 = 0;
            } else x1 = l1.val;
            if(l2 == null) {
                x2 = 0;
            } else x2 = l2.val;
            int sum = x1 + x2;
            current = sum + carry;
            result.next = new ListNode(current%10);
            if(current == 10) carry = 1;
            else {carry = current/10;}
            result = result.next;
            if(l1!=null)l1 = l1.next;
            if(l2!=null)l2 = l2.next;
        }
        return head.next;
    }


    public static void main(String[] args) {
        Solution solution = new Solution();

        ListNode l1 = ListNode.initial(1);
        ListNode l2 = ListNode.initial(9,9);

        System.out.println(solution.addTwoNumbers(l1,l2).toString());
    }
}
