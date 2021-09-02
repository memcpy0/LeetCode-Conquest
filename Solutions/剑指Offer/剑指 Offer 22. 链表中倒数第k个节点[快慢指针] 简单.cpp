/*
** Problem: https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
** Article: https://memcpy0.blog.csdn.net/article/details/109687213
** Author: memcpy0
*/
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) { //k范围合理
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *lo = head, *hi = head;
        for (int i = 0; i < k; ++i) hi = hi->next;
        while (hi) {
            hi = hi->next;
            lo = lo->next;
        }
        return lo;
    }
};