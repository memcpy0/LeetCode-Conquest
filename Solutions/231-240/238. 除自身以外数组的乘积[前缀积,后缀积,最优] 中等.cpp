/*
** Problem: https://leetcode-cn.com/problems/product-of-array-except-self/
** Article: https://memcpy0.blog.csdn.net/article/details/106559388
** Author: memcpy0
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n); 
        for (int i = 0, l = 1; i < n; l *= nums[i++]) ans[i] = l;
        for (int i = n - 1, r = 1; i >= 0; r *= nums[i--]) ans[i] *= r;
        return ans;
    }
};