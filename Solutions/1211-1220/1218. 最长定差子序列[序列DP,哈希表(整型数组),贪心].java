/*
** Problem: https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/
** Article: https://memcpy0.blog.csdn.net/article/details/121185552
** Author: memcpy0
*/
class Solution {
    int N = 40010, M = N / 2;
    public int longestSubsequence(int[] arr, int difference) {
        int n = arr.length;
        // dp[i][j]表示arr[0,i]中第i个数选择情况为j时的最长定差子序列长度
        int[][] dp = new int[n][2];
        dp[0][1] = 1;
        int[] hash = new int[N]; // 整型数组
        Arrays.fill(hash, -1);
        hash[arr[0] + M] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = 1;
            int prev = arr[i] - difference;
            if (hash[prev + M] != -1) 
                dp[i][1] = dp[hash[prev + M]][1] + 1; // 注意偏移为M
            hash[arr[i] + M] = i;
        }
        return Math.max(dp[n - 1][0], dp[n - 1][1]);
    }
}