/*
** Problem: https://leetcode.cn/problems/reverse-linked-list-ii
** Article: https://memcpy0.blog.csdn.net/article/details/132749940
** Author: memcpy0
*/
// BEST
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 设置 dummy 是此类问题的一般做法
        ListNode* dummy = new ListNode(0, head), *p0 = dummy;
        for (int i = 0; i < left - 1; ++i) p0 = p0->next;

        ListNode *prev = nullptr, *curr = p0->next;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        p0->next->next = curr;
        p0->next = prev;
        return dummy->next;
    }
};