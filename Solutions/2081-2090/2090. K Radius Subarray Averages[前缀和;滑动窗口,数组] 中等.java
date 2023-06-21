/*
** Problem: https://leetcode.cn/problems/k-radius-subarray-averages
** Article: https://memcpy0.blog.csdn.net/article/details/131335310
** Author: memcpy0
*/
// BEST: 滑动窗口
class Solution {
    public int[] getAverages(int[] nums, int k) {
        if (k == 0) return nums;
        int n = nums.length, m = 2 * k + 1;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        if (m > n) return ans;
        long sum = 0;
        for (int i = 0; i < m; ++i) sum += nums[i];
        for (int i = k; i + k < n; ++i) {
            if (i != k) sum += nums[i + k] - nums[i - k - 1];
            ans[i] = (int)(sum / m);
        }
        return ans;
    }
}

// 前缀和
class Solution {
    public int[] getAverages(int[] nums, int k) {
        if (k == 0) return nums;
        int n = nums.length, m = 2 * k + 1;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        if (m > n) return ans;
        long[] sum = new long[n + 1];
        for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + nums[i];
        for (int i = k; i + k < n; ++i) ans[i] = (int)((sum[i + k + 1] - sum[i - k]) / m);
        return ans;
    }
}