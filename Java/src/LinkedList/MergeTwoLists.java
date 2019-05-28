package LinkedList;

/**
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 * 这题意思是需要有序啊！
 */

public class MergeTwoLists {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        while (l2 != null && l1 != null) {
            if (l1.val < l2.val) {
                curr.next = new ListNode(l1.val);
                curr = curr.next;
                if(l1 != null) l1 = l1.next;
            }
            else {
                curr.next = new ListNode(l2.val);
                curr = curr.next;
                if(l2 != null) l2 = l2.next;
            }

        }
        if(l1 != null) curr.next = l1;
        if(l2 != null) curr.next = l2;
        return dummy.next;
    }
    public static void main(String[] args) {
        ListNode l1 = ListNode.initial(1,2,4);
        ListNode l2 = ListNode.initial(1,3,4);
        new MergeTwoLists().mergeTwoLists(l1,l2).toString();
    }
}

//a recursive method awesome!!!

/*public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    if(l1 == null) return l2;
    if(l2 == null) return l1;
    if(l1.val < l2.val) {
        l1.next = mergeTwoLists(l1.next,l2);
        return l1;
    }
    else {
        l2.next = mergeTwoLists(l1,l2.next);
        return l2;
    }
}*/









