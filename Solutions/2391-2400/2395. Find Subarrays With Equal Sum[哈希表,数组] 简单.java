/*
** Problem: https://leetcode.cn/problems/find-subarrays-with-equal-sum/
** Article: https://memcpy0.blog.csdn.net/article/details/129827894
** Author: memcpy0
*/
class Solution {
    public boolean findSubarrays(int[] nums) {
        HashSet<Long> rec = new HashSet<>();
        for (int i = 0; i < nums.length - 1; ++i) {
            Long sum = (long)nums[i] + nums[i + 1];
            if (rec.contains(sum)) return true;
            rec.add(sum);
        }
        return false;
    }
}