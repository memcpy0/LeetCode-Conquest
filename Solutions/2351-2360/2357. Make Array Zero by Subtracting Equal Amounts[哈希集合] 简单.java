/*
** Problem: https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/
** Article: https://memcpy0.blog.csdn.net/article/details/129937095
** Author: memcpy0
*/
class Solution {
    public int minimumOperations(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int num : nums) if (num > 0) s.add(num);
        return s.size();
    }
}