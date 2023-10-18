/*
** Problem: https://leetcode.cn/problems/validate-binary-tree-nodes/
** Article: https://memcpy0.blog.csdn.net/article/details/133898423
** Author: memcpy0
*/
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> isRoot(n, true);
        int edges = 0;
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                isRoot[leftChild[i]] = false;
                ++edges;
            }
            if (rightChild[i] != -1) {
                isRoot[rightChild[i]] = false;
                ++edges;
            }
        }
        // 从根结点连通,n个点,n-1条边
        if (edges != n - 1) return false;
        // 只有1个根结点
        int roots = 0, root = -1;
        for (int i = 0; i < n; ++i) if (isRoot[i]) { root = i; ++roots; }
        if (roots != 1) return false; // 其实可在连通性判断中处理多根情况

        queue<int> q;
        q.push(root);
        vector<bool> vis(n);
        while (!q.empty()) {
            int u = q.front();
            vis[u] = true;
            q.pop();
            if (leftChild[u] != -1) q.push(leftChild[u]);
            if (rightChild[u] != -1) q.push(rightChild[u]);
        }
        for (int i = 0; i < n; ++i) if (vis[i] == false) return false;
        return true;
    }
};