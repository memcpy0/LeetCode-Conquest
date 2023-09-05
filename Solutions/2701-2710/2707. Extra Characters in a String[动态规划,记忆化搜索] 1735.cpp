/*
** Problem: https://leetcode.cn/problems/extra-characters-in-a-string
** Article: https://memcpy0.blog.csdn.net/article/details/132693524 
** Author: memcpy0
*/
// BEST: 动态规划
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1);
        // dp[i]表示从s[i:n)中分割剩下的最少字符数
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1] + 1;
            for (string& w : dictionary) 
                if (i + w.size() <= n && s.compare(i, w.size(), w) == 0)
                    dp[i] = min(dp[i], dp[i + w.size()]);
        }
        return dp[0];
    }
};
// 记忆化搜索
class Solution {
public:
    int n;
    vector<int> dp;
    int dfs(string &s, vector<string>& d, int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i]; // 已经计算了
        dp[i] = 1 + dfs(s, d, i + 1);
        for (string& w : d) 
            if (i + w.size() <= n && s.compare(i, w.size(), w) == 0)
                dp[i] = min(dp[i], dfs(s, d, i + w.size()));
        return dp[i];
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        dp.resize(n, -1);
        return dfs(s, dictionary, 0);
    }
};