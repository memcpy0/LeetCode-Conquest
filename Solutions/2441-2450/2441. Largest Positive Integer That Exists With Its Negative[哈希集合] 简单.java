/*
** Problem: https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/
** Article: https://memcpy0.blog.csdn.net/article/details/130660588
** Author: memcpy0
*/
class Solution {
    public int findMaxK(int[] nums) {
        var rec = new HashSet<Integer>();
        int ans = -1;
        for (int i : nums) {
            if (rec.contains(-i)) ans = Math.max(ans, Math.abs(i));
            rec.add(i);
        }
        return ans;
    }
}