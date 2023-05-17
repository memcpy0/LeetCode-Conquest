/*
** Problem: https://leetcode.cn/problems/reverse-subarray-to-maximize-array-value
** Article: https://memcpy0.blog.csdn.net/article/details/130663967
** Author: memcpy0
*/
class Solution {
    public int maxValueAfterReverse(int[] nums) {
	int base = 0, d = 0, n = nums.length;
	int mx = Integer.MIN_VALUE, mn = Integer.MAX_VALUE;
	for (int i = 1; i < n; ++i) {
	    int a = nums[i - 1], b = nums[i];
	    int dab = Math.abs(a - b);
	    base += dab;
	    mx = Math.max(mx, Math.min(a, b));
	    mn = Math.min(mn, Math.max(a, b));
	    d = Math.max(d, Math.max(Math.abs(nums[0] - b) - dab, // i = 0
				     Math.abs(nums[n - 1] - a) - dab)); // j = n-1
	}
	return base + Math.max(d, 2 * (mx - mn));
    }
}