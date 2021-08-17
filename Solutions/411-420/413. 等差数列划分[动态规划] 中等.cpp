/*
** Problem: https://leetcode-cn.com/problems/arithmetic-slices
** Article: https://memcpy0.blog.csdn.net/article/details/119641437
** Author: memcpy0
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() <= 2) return 0;
        int n = nums.size(), ans = 0;
        vector<int> dp(n); //dp[i]为以nums[i]结尾的等差数组的数目
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
                ans += dp[i];
            } 
        } 
        return ans;
    }
};