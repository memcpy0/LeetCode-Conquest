/*
** Problem: https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
** Article: https://memcpy0.blog.csdn.net/article/details/131269718
** Author: memcpy0
*/
// 链表+哈希表+前缀和
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) { 
        ListNode dummy = new ListNode(0, head);
        var sum = new HashMap<Integer, ListNode>();
        ListNode cur = dummy; 
        int s = 0;
        while (cur != null) {
            s += cur.val;
            sum.put(s, cur); // 对于同一前缀和,后面的节点覆盖前面的节点
            cur = cur.next;
        }
        s = 0;
        cur = dummy;
        while (cur != null) {
            s += cur.val;
            cur.next = sum.get(s).next; // 如果没有相同的前缀和,得到的节点就是s
            cur = cur.next;
        }
        return dummy.next; 
    }
}

// 链表+递归
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) { 
        if (head == null) return null;
        int sum = 0;
        for (ListNode p = head; p != null; p = p.next) {
            sum += p.val;
            if (sum == 0) return removeZeroSumSublists(p.next);
        }
        head.next = removeZeroSumSublists(head.next);
        return head; 
    }
}

