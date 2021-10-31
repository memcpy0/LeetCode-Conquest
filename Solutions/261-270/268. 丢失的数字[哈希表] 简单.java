/*
** Problem: https://leetcode-cn.com/problems/missing-number/
** Article: https://memcpy0.blog.csdn.net/article/details/106988398
** Author: memcpy0
*/
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length; // n个数
        int[] cnt = new int[n + 1];
        for (int v : nums) ++cnt[v];
        for (int i = 0; i <= n; ++i)
            if (cnt[i] == 0) return i;
        return -1;
    }
}