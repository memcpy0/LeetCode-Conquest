/*
** Problem: https://leetcode.cn/problems/delete-nodes-and-return-forest/
** Article: https://memcpy0.blog.csdn.net/article/details/130945416
** Author: memcpy0
*/
class Solution { 
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        bitset<1010> bst;
        for (int del : to_delete) bst[del] = 1;
        function<TreeNode*(TreeNode*, bool)> dfs = [&](TreeNode* root, bool isTree) -> TreeNode* {
            if (root == nullptr) return nullptr; 
            bool flag = bst[root->val];
            if (isTree && !flag) ans.push_back(root);
            root->left = dfs(root->left, flag);
            root->right = dfs(root->right, flag);
            return flag ? nullptr : root;
        };
        dfs(root, true); 
        return ans;
    }
};
/*
class Solution {
private:
    vector<TreeNode*> ans;
    bitset<1010> bst;
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) return nullptr;
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if (!bst[root->val]) return root;
        if (root->left) ans.push_back(root->left);
        if (root->right) ans.push_back(root->right);
        return nullptr;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int del : to_delete) bst[del] = 1;
        root = dfs(root);
        if (root) ans.push_back(root);
        return ans;
    }
};
*/