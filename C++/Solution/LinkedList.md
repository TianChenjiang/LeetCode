`ListNode* head` 指向LinkedList第一个元素 可以用`-> `操作符调用成员函数

```c++
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val): val(x), next(NULL){}
};

ListNode* head = new ListNode(1); //初始化后的类型为ListNode::ListNode 是指向节点的指针
// (*head).val 等价于 head->val 
// 解引用，然后调用对象的val或者next
```


遍历LinkedList时用while条件：
注意初始元素
注意末尾元素
把null赋值给指针不会报错 只有取val才会报错空指针


### 获得Linkedlist长度


```java
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
    }
}
```

注意事项：

当链表为空时，不能使用`l1.val`或者`l1.next` 所以当遍历时，需要每步都进行判断



链表的初始化:

```java
 public static ListNode initial(int...vals) {
        ListNode head = new ListNode(0);
        ListNode current = head;
        for(int val : vals){
            current.next = new ListNode(val);
            current = current.next;
        }
        return head.next;
 }
```

链表转为字符串：

```java
public String toString(){
        String s = "";
        ListNode current = this;
        while (current != null) {
            s = s + " " + current.val;
            current = current.next;
        }
        return s;
}
```
