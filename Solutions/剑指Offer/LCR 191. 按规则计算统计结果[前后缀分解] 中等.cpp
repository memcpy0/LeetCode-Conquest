/*
** Problem: https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/
** Article: https://memcpy0.blog.csdn.net/article/details/133855538
** Author: memcpy0
*/
// BEST
class Solution {
public:
    vector<int> statisticalResult(vector<int>& arrayA) {
        int n = arrayA.size();
        vector<int> ans(n);
        for (int i = 0, pre = 1; i < n; pre *= arrayA[i++]) ans[i] = pre;
        for (int i = n - 1, suf = 1; i >= 0; suf *= arrayA[i--]) ans[i] *= suf;
        return ans;
    }
};