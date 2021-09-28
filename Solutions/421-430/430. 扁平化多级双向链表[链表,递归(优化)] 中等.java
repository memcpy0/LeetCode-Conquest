/*
** Problem: https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/
** Article: https://memcpy0.blog.csdn.net/article/details/120468312
** Author: memcpy0
*/
class Solution {
    private Node flattenReturnTail(Node head) {
        Node last = head;
        while (head != null) {
            if (head.child == null) {
                last = head;
                head = head.next;
            } else {
                Node childLast = flattenReturnTail(head.child);
                Node temp = head.next;
                head.next = head.child; //和扁平化链表头部连接
                head.child.prev = head;
                head.child = null; //置为空
                // if (childLast != null) 
                childLast.next = temp; //尾结点childLast一定非空; 和扁平化链表尾部连接
                if (temp != null) temp.prev = childLast;
                last = head;
                head = childLast;
            }
        }
        return last;
    }
    public Node flatten(Node head) {
        flattenReturnTail(head); //函数不会改变头节点
        return head;
    }
}