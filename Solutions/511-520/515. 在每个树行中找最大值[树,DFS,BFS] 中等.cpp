/*
** Problem: https://leetcode.cn/problems/find-largest-value-in-each-tree-row
** Article: https://memcpy0.blog.csdn.net/article/details/115265602
** Author: memcpy0
*/
// DFS
class Solution {
public:
    void dfs(vector<int>& res, TreeNode* root, int curHeight) {
        if (curHeight == res.size()) {
            res.push_back(root->val);
        } else {
            res[curHeight] = max(res[curHeight], root->val);
        }
        if (root->left) dfs(res, root->left, curHeight + 1);
        if (root->right) dfs(res, root->right, curHeight + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        dfs(res, root, 0);
        return res;
    }
};
// BFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(), maxval = INT_MIN;
            for (int i = 0; i < size; ++i) {
                TreeNode *t = q.front(); q.pop();
                if (t->val > maxval) maxval = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            ans.push_back(maxval);
        }
        return ans;
    }
};