/*
** Problem: https://leetcode-cn.com/problems/single-number/
** Article: https://memcpy0.blog.csdn.net/article/details/106988806
** Author: memcpy0
*/
class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> rec = new HashMap<>();
        for (int v : nums) rec.put(v, rec.getOrDefault(v, 0) + 1);
        for (int v : rec.keySet())
            if (rec.get(v) == 1) 
                return v;
        return 0;
    }
}