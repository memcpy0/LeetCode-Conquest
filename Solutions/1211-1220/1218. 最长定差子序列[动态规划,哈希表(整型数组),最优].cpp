/*
** Problem: https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/
** Article: https://memcpy0.blog.csdn.net/article/details/121185552
** Author: memcpy0
*/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;
        for (const int &i : arr)
            ans = max(ans, dp[i] = dp[i - difference] + 1);
        return ans;
    }
};

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        const int N = 40010, M = N / 2;
        vector<int> dp(N);
        int ans = 0;
        for (const int &i : arr)
            ans = max(ans, dp[i + M] = dp[i + M - difference] + 1);
        return ans;
    }
};