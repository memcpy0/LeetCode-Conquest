/*
** Problem: https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/
** Article: https://memcpy0.blog.csdn.net/article/details/120468312
** Author: memcpy0
*/
class Solution {
    public Node flatten(Node head) {
        Node dummyHead = new Node(0);
        dummyHead.next = head;
        while (head != null) {
            if (head.child == null) {
                head = head.next;
            } else {
                Node temp = head.next;
                head.next = head.child; //和扁平化链表头部连接
                head.child.prev = head;
                head.child = null; //置为空
                Node last = head;
                while (last.next != null) last = last.next;
                last.next = temp;
                if (temp != null) temp.prev = last; //和扁平化链表尾部连接
                head = head.next;
            }
        }
        return dummyHead.next;
    }
}