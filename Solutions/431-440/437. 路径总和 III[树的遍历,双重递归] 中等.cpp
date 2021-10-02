/*
** Problem: https://leetcode-cn.com/problems/path-sum-iii/
** Article: https://memcpy0.blog.csdn.net/article/details/107207793
** Author: memcpy0
*/
class Solution {
private:
    //在以node为根结点的二叉树中,寻找包含node、和为num的路径个数
    int findPath(TreeNode* node, int num) {
        if (node == nullptr) return 0;
        int res = 0;
        if (node->val == num) ++res;
        //如果node的值可能是负数,则加上后续的路径值的和仍然可能等于num
        res += findPath(node->left, num - node->val);
        res += findPath(node->right, num - node->val);
        return res;
    }
public: 
    //在以root为根结点的二叉树中,寻找和为sum的路径,返回这样的路径个数
    int pathSum(TreeNode* root, int sum) { 
        if (root == nullptr) return 0;
        int res = findPath(root, sum); //寻找包含root并且和为sum的路径
        //处理不包含root结点且和为sum的路径数目
        res += pathSum(root->left, sum);    
        res += pathSum(root->right, sum);
        return res;
    }
};