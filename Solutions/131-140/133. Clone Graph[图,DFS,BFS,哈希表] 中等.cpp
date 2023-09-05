/*
** Problem: https://leetcode.cn/problems/clone-graph
** Article: https://memcpy0.blog.csdn.net/article/details/132690667
** Author: memcpy0
*/
// BEST: DFS+哈希表
class Solution {
public:
    unordered_map<Node*, Node*> vis;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
        if (vis.find(node) != vis.end()) return vis[node];
        // 克隆节点，注意为了深拷贝我们不会克隆它的邻居的列表
        Node* cloneNode = new Node(node->val);
        // 哈希表存储
        vis[node] = cloneNode;
        // 遍历该节点的邻居并更新克隆节点的邻居列表
        for (Node *neighbor : node->neighbors)
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        return cloneNode;
    }
};
// BFS+哈希表
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> vis;
        // 将题目给定的节点添加到队列
        queue<Node*> q;
        q.push(node);
        // 克隆第一个节点并存储到哈希表中
        vis[node] = new Node(node->val);
        
        while (!q.empty()) {
            // 取出队列头节点
            Node *cur = q.front(); q.pop();                
            for (auto& neighbor: cur->neighbors) {
                if (vis.find(neighbor) == vis.end()) {
                    // 如果没有被访问过，就克隆并存储在哈希表中
                    vis[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // 更新当前节点的邻居列表
                vis[cur]->neighbors.emplace_back( vis[neighbor] );
            }
        }
        return vis[node];
    }
};