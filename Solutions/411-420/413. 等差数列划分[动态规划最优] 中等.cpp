/*
** Problem: https://leetcode-cn.com/problems/arithmetic-slices
** Article: https://memcpy0.blog.csdn.net/article/details/119641437
** Author: memcpy0
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() <= 2) return 0;
        int n = nums.size(), ans = 0, dp = 0;
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                ++dp; //dp[i]=dp[i-1]+1;
                ans += dp;
            } else dp = 0;
        } 
        return ans;
    }
};