/*
** Problem: https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/
** Article: https://memcpy0.blog.csdn.net/article/details/120468312
** Author: memcpy0
*/
class Solution {
private:
    Node dummyHead, *pre = &dummyHead;
    void dfs(Node* head) {
        if (head == nullptr) return;
        head->prev = pre; pre->next = head; pre = pre->next;
        Node *tempNext = pre->next, *tempChild = pre->child;
        pre->next = pre->child = nullptr; //置为nullptr
        dfs(tempChild);
        dfs(tempNext);
    }
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        dfs(head);
        Node *newHead = dummyHead.next; 
        //否则可能报错The linked list...is not a valid doubly linked list. 
        dummyHead.next = nullptr, newHead->prev = nullptr; 
        return newHead;
    }
};