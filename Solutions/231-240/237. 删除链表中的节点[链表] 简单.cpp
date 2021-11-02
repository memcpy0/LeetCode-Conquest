/*
** Problem: https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
** Article: https://memcpy0.blog.csdn.net/article/details/108183127
** Author: memcpy0
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode *delNode = node->next;
        node->next = node->next->next;
        delete delNode;
    }
};