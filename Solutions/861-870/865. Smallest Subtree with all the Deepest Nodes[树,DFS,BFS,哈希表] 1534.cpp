/*
** Problem: https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes
** Article: https://memcpy0.blog.csdn.net/article/details/132748063
** Author: memcpy0
*/
class Solution {
public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        TreeNode *ans = nullptr;
        int max_depth = -1; // 全局最大深度
        function<int(TreeNode*, int)> dfs = [&](TreeNode *node, int depth) {
            if (node == nullptr) {
                max_depth = max(max_depth, depth); // 维护全局最大深度
                return depth;
            }
            int left_max_depth = dfs(node->left, depth + 1); // 获取左子树最深叶节点的深度
            int right_max_depth = dfs(node->right, depth + 1); // 获取右子树最深叶节点的深度
            if (left_max_depth == right_max_depth && left_max_depth == max_depth)
                ans = node;
            return max(left_max_depth, right_max_depth); // 当前子树最深叶节点的深度
        };
        dfs(root, 0);
        return ans;
    }
};
// BEST: DFS
class Solution {
    pair<int, TreeNode*> dfs(TreeNode *node) {
        if (node == nullptr)
            return {0, nullptr};
        auto [left_height, left_lca] = dfs(node->left);
        auto [right_height, right_lca] = dfs(node->right);
        if (left_height > right_height) // 左子树更高
            return {left_height + 1, left_lca};
        if (left_height < right_height) // 右子树更高
            return {right_height + 1, right_lca};
        return {left_height + 1, node}; // 一样高
    }

public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        return dfs(root).second;
    }
};

class Solution {
public:
    int depth[1010];
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* left = root->left, *right = root->right;
        TreeNode* lcaLeft = subtreeWithAllDeepest(root->left), *lcaRight = subtreeWithAllDeepest(root->right);
        int dl = left ? depth[left->val] : 0, dr = right ? depth[right->val] : 0;
        depth[root->val] = max(dl, dr) + 1;
        if (dl > dr) return lcaLeft;
        if (dr > dl) return lcaRight;
        return root;
    }
};