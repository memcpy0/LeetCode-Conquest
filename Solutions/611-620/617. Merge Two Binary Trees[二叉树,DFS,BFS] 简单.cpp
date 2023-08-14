/*
** Problem: https://leetcode.cn/problems/merge-two-binary-trees
** Article: https://memcpy0.blog.csdn.net/article/details/108761805
** Author: memcpy0
*/
// BEST: DFS
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        return new TreeNode(root1->val + root2->val,
            mergeTrees(root1->left, root2->left),  // 合并左子树
            mergeTrees(root1->right, root2->right) // 合并右子树
        );
    }
};