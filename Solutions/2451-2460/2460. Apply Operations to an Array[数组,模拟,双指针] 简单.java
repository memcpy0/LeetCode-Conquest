/*
** Problem: https://leetcode.cn/problems/apply-operations-to-an-array
** Article: https://memcpy0.blog.csdn.net/article/details/131046304
** Author: memcpy0
*/
class Solution {
    private void swap(int[] nums, int i, int j) {
        int t = nums[i]; nums[i] = nums[j]; nums[j] = t;
    }
    public int[] applyOperations(int[] nums) {
        int n = nums.length;
        for (int i = 0, j = 0; i < n; ++i) {
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i] != 0) swap(nums, i, j++); // j标志非零数组的下一个元素
        }
        return nums;
    }
}