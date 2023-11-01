/*
** Problem: https://leetcode.cn/problems/find-mode-in-binary-search-tree/
** Article: https://memcpy0.blog.csdn.net/article/details/134173018
** Author: memcpy0
*/
// BEST:真正的O(1)空间
class Solution {
public:
    int base, count, maxCount;
    void update(int x) {
        if (x == base) ++count;
        else { count = 1, base = x; }
        if (count == maxCount) answer.push_back(base);
        if (count > maxCount) { maxCount = count; answer = vector<int> { base }; }
    }
    vector<int> findMode(TreeNode* root) {
        TreeNode *cur = root, *pre = nullptr;
        while (cur) {
            if (!cur->left) {
                update(cur->val);
                cur = cur->right;
                continue;
            }
            pre = cur->left;
            while (pre->right && pre->right != cur) {
                pre = pre->right;
            }
            if (!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                update(cur->val);
                cur = cur->right;
            }
        }
        return answer;
    }
};