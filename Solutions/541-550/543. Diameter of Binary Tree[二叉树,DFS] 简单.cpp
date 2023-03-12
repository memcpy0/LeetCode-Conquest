/*
** Problem: https://leetcode.cn/problems/diameter-of-binary-tree/
** Article: https://memcpy0.blog.csdn.net/article/details/129479473
** Author: memcpy0
*/
class Solution {
private:
    int ans = 0;
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        int dl = depth(root->left), dr = depth(root->right);
        ans = max(ans, dl + dr + 1); // 计算d_node即L+R+1 并更新ans
        return max(dl, dr) + 1; // 当前节点的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans - 1;
    }
};