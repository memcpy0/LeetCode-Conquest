/*
** Problem: https://leetcode-cn.com/problems/single-number-iii/
** Article: https://memcpy0.blog.csdn.net/article/details/121064507
** Author: memcpy0
*/
class Solution {
    public int[] singleNumber(int[] nums) {
        Map<Integer, Integer> rec = new HashMap<>();
        for (int i : nums) rec.put(i, rec.getOrDefault(i, 0) + 1);
        int[] ans = new int[2];
        int idx = 0;
        for (int i : nums)
            if (rec.get(i) == 1) ans[idx++] = i;
        return ans;
    }
}