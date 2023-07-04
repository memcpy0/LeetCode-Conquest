/*
** Problem: https://leetcode.cn/problems/add-two-numbers-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/109496392
** Author: memcpy0
*/
// BEST: 链表+双栈
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode *t1 = l1, *t2 = l2;
        while (t1) { s1.push(t1->val); t1 = t1->next; }
        while (t2) { s2.push(t2->val); t2 = t2->next; }
        int c = 0;
        ListNode dummy;
        while (!s1.empty() || !s2.empty() || c) {
            if (!s1.empty()) { c += s1.top(); s1.pop(); }
            if (!s2.empty()) { c += s2.top(); s2.pop(); }
            dummy.next = new ListNode(c % 10, dummy.next);
            c /= 10;
        }
        return dummy.next;
    }
};
// 反转链表
class Solution {
private:
    ListNode* reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *newHead = reverseList(head->next); // 传递不变的新链表头指针,即原链表尾指针
        head->next->next = head; // 把下个节点指向自己,即把新链表的指针连接上一个节点
        head->next = NULL; // 新节点作为新链表的结尾
        return newHead;
    } 
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = reverseList(l1), *q = reverseList(l2);
        ListNode dummy;
        int carry = 0; 
        while (p || q || carry) {
            if (p) { carry += p->val; p = p->next; }
            if (q) { carry += q->val; q = q->next; }
            dummy.next = new ListNode(carry % 10, dummy.next);
            carry /= 10;  
        } 
        return dummy.next;
    }
};