/*
** Problem: https://leetcode.cn/problems/minimum-cost-to-merge-stones/
** Article: https://memcpy0.blog.csdn.net/article/details/130307614
** Author: memcpy0
*/
class Solution {
public:
    int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1; // 不能合并为一堆
        int sum[n + 1]; memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + stones[i];
        int dp[n][n][k + 1]; memset(dp, -1, sizeof(dp)); // -1表示没计算过
        // dp[i][j][p]: 把stones[i:j]合并为p堆的最低成本
        function<int(int, int, int)> dfs = [&](int i, int j, int p) -> int {
            int &ans = dp[i][j][p];
            if (ans != -1) return ans;
            if (p == 1) { // 将stones[i:j]中的k堆石头合并为1堆,成本为这K堆石头数的和 
                return ans = i == j ? 0 : dfs(i, j, k) + sum[j + 1] - sum[i]; // 当然,先要将stones[i:j]的石头合并为k堆
            }
            ans = INT_MAX; 
            for (int m = i; m < j; m += (k - 1)) // [m,m+k)
                ans = min(ans, dfs(i, m, 1) + dfs(m + 1, j, p - 1));
            return ans;
        };
        return dfs(0, n - 1, 1);
    }
}; 

class Solution {
public:
    int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1; // 无法合并成一堆
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; i++) s[i + 1] = s[i] + stones[i]; // 前缀和
        int dp[n][n];
        memset(dp, -1, sizeof(dp)); // -1 表示还没有计算过
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i == j) return 0; // 只有一堆石头，无需合并
            int &ans = dp[i][j]; // 注意这里是引用，下面会直接修改 dp[i][j]
            if (ans != -1) return ans;
            ans = INT_MAX;
            for (int m = i; m < j; m += k - 1) // 枚举哪些石头堆合并成第一堆
                ans = min(ans, dfs(i, m) + dfs(m + 1, j));
            if ((j - i) % (k - 1) == 0) ans += s[j + 1] - s[i]; // 可以合并成一堆
            return ans;
        };
        return dfs(0, n - 1);
    }
};

class Solution {
public:
    int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1; // 无法合并成一堆  
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; i++) s[i + 1] = s[i] + stones[i]; // 前缀和 
        int f[n][n];
        for (int i = n - 1; i >= 0; --i) {
            f[i][i] = 0;
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = INT_MAX;
                for (int m = i; m < j; m += k - 1)
                    f[i][j] = min(f[i][j], f[i][m] + f[m + 1][j]);
                if ((j - i) % (k - 1) == 0) // 可以合并成一堆
                    f[i][j] += s[j + 1] - s[i];
            }
        }
        return f[0][n - 1];
    }
};