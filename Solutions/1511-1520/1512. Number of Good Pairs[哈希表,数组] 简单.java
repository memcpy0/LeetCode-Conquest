/*
** Problem: https://leetcode.cn/problems/number-of-good-pairs/
** Article: https://memcpy0.blog.csdn.net/article/details/130626730
** Author: memcpy0
*/
class Solution {
    public int numIdenticalPairs(int[] nums) {
        int[] rec = new int[101];
        int ans = 0;
        for (int n : nums) { ans += rec[n]; ++rec[n]; }
        return ans;
    }
}