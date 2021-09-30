/*
** Problem: https://leetcode-cn.com/problems/maximum-difference-between-increasing-elements/
** Article: https://memcpy0.blog.csdn.net/article/details/120559756
** Author: memcpy0
*/
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, premin = nums[0];
        for (int i = 1, n = nums.size(); i < n; ++i) {
            if (premin < nums[i]) ans = max(ans, nums[i] - premin);
            else premin = nums[i];
        }
        return ans;
    }
};