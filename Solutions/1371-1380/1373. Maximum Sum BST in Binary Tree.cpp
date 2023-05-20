/*
** Problem: https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/
** Article: https://memcpy0.blog.csdn.net/article/details/130779467
** Author: memcpy0
*/
class Solution {
public:
    int maxsum = 0;
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxsum;
    }
    vector<int> dfs(TreeNode* root) {
        if (!root) return {true, INT_MAX, INT_MIN, 0};
        auto lArr = dfs(root->left);
        auto rArr = dfs(root->right);
        int sum = 0, curmax, curmin;
        if (!lArr[0] || !rArr[0] || root->val >= rArr[1] || root->val <= lArr[2]) 
            return {false, 0, 0, 0};
        curmin = root->left ? lArr[1] : root->val;
        curmax = root->right ? rArr[2] : root->val;
        sum += (root->val + lArr[3] + rArr[3]);
        maxsum = max(maxsum, sum);
        return {true, curmin, curmax, sum};
    }
};