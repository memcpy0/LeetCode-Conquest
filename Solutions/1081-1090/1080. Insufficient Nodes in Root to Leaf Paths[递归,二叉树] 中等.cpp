/*
** Problem: https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/
** Article: https://memcpy0.blog.csdn.net/article/details/130813811
** Author: memcpy0
*/
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root == nullptr) return root;
        limit -= root->val; // 是叶子结点 // 如果limit>0,说明从根到叶子的路径和小于limit,删除叶子,否则不删除
        if (root->left == root->right) return limit <= 0 ? root : nullptr; 
        root->left = sufficientSubset(root->left, limit);
        root->right = sufficientSubset(root->right, limit);
        return root->left || root->right ? root : nullptr; // 有儿子没被删除,说明有可能>=limit,不是不足结点 
    }
};