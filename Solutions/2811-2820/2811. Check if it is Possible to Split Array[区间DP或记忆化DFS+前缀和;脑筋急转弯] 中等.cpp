/*
** Problem: https://leetcode.cn/problems/check-if-it-is-possible-to-split-array
** Article: https://memcpy0.blog.csdn.net/article/details/132251191
** Author: memcpy0
*/
// BEST
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        for (int i = 1; i < n; ++i)
            if (nums[i - 1] + nums[i] >= m) return true;
        return n <= 2;
    }
};

// 记忆化DFS+前缀和
class Solution {
private:
    int m;
    int sum[110];
    int dp[110][110];
    int dfs(int l, int r) {
        if (dp[l][r] != -1) return dp[l][r]; // 已经有答案
        if (l + 1 >= r) return dp[l][r] = 1; // 拆分前进行判断,可以拆分
        if (sum[r + 1] - sum[l] <= m) return dp[l][r] = 0; // 拆分前进行判断,不可拆分
        int left = 0, right = 0;
        if (l + 1 == r || sum[r + 1] - sum[l + 1] >= m) // 看是否可以拆分出[l+1,r]这个子数组
            left = dfs(l + 1, r); // 看[l+1,r]子数组是否可继续拆分
        if (l == r - 1 || sum[r] - sum[l] >= m) // 看是否可以拆分出[l,r-1]这个子数组
            right = dfs(l, r - 1); // 看[l,r-1]子数组是否可继续拆分
        return dp[l][r] = left || right; 
    }
public:
    bool canSplitArray(vector<int>& nums, int m) {
        this->m = m;
        memset(sum, 0, sizeof(sum));
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + nums[i];
        return dfs(0, n - 1);
    }
};

// 区间DP+前缀和
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int sum[110];
        bool dp[110][110];
        memset(sum, 0, sizeof(sum));
        memset(dp, false, sizeof(dp));
        int n = nums.size();
        for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + nums[i];
        // dp[i][j]表示区间[i,j]能否拆分
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = true;
            if (i + 1 < n) dp[i][i + 1] = true;
            // 区间[i,j-1], [i+1,j]是否可拆
            for (int j = i + 2; j < n; ++j) {
                // [i,j]能否拆分为[i+1,j]或[i,j-1],看拆出子数组的和是否>=m,且拆出子数组是否可继续拆分
                if (sum[j] - sum[i] >= m && dp[i][j - 1]
                    || sum[j + 1] - sum[i + 1] >= m && dp[i + 1][j])
                    dp[i][j] = true;        
            }
        }
        return dp[0][n - 1];
    }
};