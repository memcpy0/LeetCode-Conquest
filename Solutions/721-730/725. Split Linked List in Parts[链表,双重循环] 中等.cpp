/*
** Problem: https://leetcode.cn/problems/split-linked-list-in-parts/
** Article: https://memcpy0.blog.csdn.net/article/details/132748279
** Author: memcpy0
*/
// BEST
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode *temp = head;
        while (temp) { ++n; temp = temp->next; }
        int quotient = n / k, remainder = n % k;
        vector<ListNode*> parts(k, nullptr);
        ListNode* curr = head;
        for (int i = 0; i < k && curr; ++i) {
            parts[i] = curr;
            int partSize = quotient + (i < remainder ? 1 : 0);
            for (int j = 1; j < partSize; ++j) curr = curr->next;
            ListNode *next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        return parts;
    }
};