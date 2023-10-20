/*
** Problem: https://leetcode.cn/problems/lru-cache
** Article: https://memcpy0.blog.csdn.net/article/details/109188260
** Author: memcpy0
*/
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev, *next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head, *tail;
    int size, capacity;
public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        // 使用dummy头部和尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if (!cache.count(key)) return -1;
        // 如果key存在,先通过哈希表定位,再移动到尾部
        DLinkedNode* node = cache[key];
        moveToTail(node);
        return node->value;
    }
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果key不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加进双向链表的尾部
            addToTail(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的头部节点
                DLinkedNode* removed = removeHead();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄露
                delete removed;
                --size;
            }
        } else {
            // 如果key存在，先通过哈希表定位，再修改value，并移到尾部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToTail(node);
        }
    }
    void addToTail(DLinkedNode* node) {
        node->prev = tail->prev;
        tail->prev->next = node;
        node->next = tail;
        tail->prev = node;
    }
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void moveToTail(DLinkedNode* node) {
        removeNode(node);
        addToTail(node);
    }
    DLinkedNode* removeHead() {
        DLinkedNode* node = head->next;
        removeNode(node);
        return node;
    }
};