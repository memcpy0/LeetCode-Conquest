/*
** Problem: https://leetcode-cn.com/problems/running-sum-of-1d-array/
** Article: https://memcpy0.blog.csdn.net/article/details/109634506
** Author: memcpy0
*/
class Solution {
    public int[] runningSum(int[] nums) {
        int[] ans = new int[nums.length];
        int sum = 0;
        for (int i = 0; i < nums.length; ++i) {
            sum += nums[i];
            ans[i] = sum;
        }
        return ans;
    }
}