/*
** Problem: https://leetcode-cn.com/problems/longest-palindromic-subsequence/
** Article: https://memcpy0.blog.csdn.net/article/details/120108474
** Author: memcpy0
*/
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        char[] cs = s.toCharArray();
        int[][] dp = new int[n][n];
        for (int len = 1; len <= n; ++len) {
            for (int l = 0; l + len - 1 < n; ++l) { //右端点在范围内
                int r = l + len - 1;
                if (len == 1) dp[l][r] = 1;
                else if (len == 2) dp[l][r] = (cs[l] == cs[r]) ? 2 : 1; //注意特判
                else dp[l][r] = Math.max(
                    dp[l + 1][r - 1] + (cs[l] == cs[r] ? 2 : 0),
                    Math.max(dp[l + 1][r], dp[l][r - 1])
                );
            }
        }
        return dp[0][n - 1];
    }
}