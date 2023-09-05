/*
** Problem: https://leetcode.cn/problems/copy-list-with-random-pointer
** Article: https://memcpy0.blog.csdn.net/article/details/132691931
** Author: memcpy0
*/
// BEST: DFS+哈希表
class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (!cachedNode.count(head)) {
            Node* headNew = new Node(head->val);
            cachedNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};
// 迭代+哈希表+巧妙写法
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> cachedNode;
        
        Node* cur = head;
        while (cur) {
            cachedNode[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            cachedNode[cur]->next = cachedNode[cur->next];
            cachedNode[cur]->random = cachedNode[cur->random];
            cur = cur->next;
        }
        return cachedNode[head];
    }
};
// 迭代+拷贝拆分+三次遍历
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (Node* node = head; node; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node* node = head; node; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random = node->random ? node->random->next : nullptr;
        }
        Node* headNew = head->next;
        for (Node* node = head; node; node = node->next) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = nodeNew->next ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};