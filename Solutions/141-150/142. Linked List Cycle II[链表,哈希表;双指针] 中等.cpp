/*
** Problem: https://leetcode.cn/problems/linked-list-cycle-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/110139454
** Author: memcpy0
*/
// BEST: 快慢指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        } 
        return nullptr;
    }
};