/*
** Problem: https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/
** Article: https://memcpy0.blog.csdn.net/article/details/121185552
** Author: memcpy0
*/
class Solution {
    int N = 40010, M = N / 2;
    public int longestSubsequence(int[] arr, int difference) {
        int n = arr.length;
        // dp[i]表示arr[0,i]中选择第i个数时的最长定差子序列长度
        int[] dp = new int[n];
        dp[0] = 1;
        int[] hash = new int[N]; // 整型数组
        Arrays.fill(hash, -1);
        hash[arr[0] + M] = 0;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            dp[i] = 1;
            int prev = arr[i] - difference;
            if (hash[prev + M] != -1) 
                dp[i] = dp[hash[prev + M]] + 1; // 注意偏移为M
            hash[arr[i] + M] = i;
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
}