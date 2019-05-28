package LinkedList;

public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
    }

    public String toString(){
        String s = "";
        ListNode current = this;
        while (current != null) {
            s = s + " " + current.val;
            current = current.next;
        }
        System.out.println(s);
        return s;
    }

    public static ListNode initial(int...vals) {
        ListNode head = new ListNode(0);
        ListNode current = head;
        for(int val : vals){
            current.next = new ListNode(val);
            current = current.next;
        }
        return head.next;
    }
}

