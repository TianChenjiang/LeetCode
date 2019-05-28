package LinkedList;

public class RemoveNthFromEnd{
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //get the length of the linkedList
        int count = 0;
        ListNode curr = head;
        while (curr != null) {
            count++;
            curr = curr.next;
        }
        n = count - n;
        curr = head;
        if(n == 0) {
            curr = head.next;
            return curr;
        }
        for (int i = 0; i < n-1; i++) {
            curr = curr.next;
        }
        if (curr != null && curr.next != null) curr.next = curr.next.next;
        return head;
    }

    public static void main(String[] args){
        ListNode l = ListNode.initial(1,2,3);
        new RemoveNthFromEnd().removeNthFromEnd(l, 3).toString();

    }


}

//遍历一次的方法 -- 用两个指针










