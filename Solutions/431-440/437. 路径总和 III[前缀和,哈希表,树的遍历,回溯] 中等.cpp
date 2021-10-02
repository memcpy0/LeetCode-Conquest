/*
** Problem: https://leetcode-cn.com/problems/path-sum-iii/
** Article: https://memcpy0.blog.csdn.net/article/details/107207793
** Author: memcpy0
*/
class Solution {
private:
    unordered_map<int, int> rec;
    int ans = 0, target = 0; //返回结果
    void dfs(TreeNode* root, int sum) {
        ans += rec[sum - target]; //可能不存在sum-target,于是ans+=0
        ++rec[sum];
        if (root->left) dfs(root->left, sum + root->left->val);
        if (root->right) dfs(root->right, sum + root->right->val);
        --rec[sum]; //注意回溯
    }
public:
    int pathSum(TreeNode* root, int sum) { 
        if (root == nullptr) return 0;
        target = sum;
        rec[0] = 1;
        dfs(root, root->val);
        return ans;
    }
};