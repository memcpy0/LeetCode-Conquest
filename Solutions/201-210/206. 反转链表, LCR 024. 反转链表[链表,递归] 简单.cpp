/*
** Problem: https://leetcode.cn/problems/reverse-linked-list/
** Article: https://memcpy0.blog.csdn.net/article/details/108177690
** Author: memcpy0
*/
// 迭代
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *newHead = nullptr, *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = next;
        }
        return newHead;
    }
};
// 递归
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};