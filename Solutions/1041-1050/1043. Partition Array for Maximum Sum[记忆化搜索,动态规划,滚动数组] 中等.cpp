/*
** Problem: https://leetcode.cn/problems/partition-array-for-maximum-sum/
** Article: https://memcpy0.blog.csdn.net/article/details/130260221
** Author: memcpy0
*/
class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size(), dp[k];
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = i, mx = 0; j > i - k && j >= 0; --j) {
                mx = max(mx, arr[j]); // 一边枚举 j，一边计算子数组的最大值
                // 注意在循环结束前，f[(i+1)%k] 是需要用到的，不能提前覆盖
                res = max(res, dp[j % k] + (i - j + 1) * mx);
            }
            dp[(i + 1) % k] = res;
        }
        return dp[n % k];
    }
};

/*
class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
		int n = arr.size(), dp[n];
		memset(dp, -1, sizeof(dp)); // -1表示没被计算过
		function<int(int)> dfs = [&](int i) -> int {
			if (i < 0) return 0;
			int &res = dp[i]; // 下面会直接修改dp[i]
			if (res != -1) return res;
			for (int j = i, mx = 0; j > i - k && j >= 0; --j) {
				mx = max(mx, arr[j]); // 一边枚举j,一边计算子数组的最大值
				res = max(res, dfs(j - 1) + (i - j + 1) * mx);
			}
			return res;
		};
		return dfs(n - 1);
	}
};
*/

/*
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(), dp[n + 1];
        dp[0] = 0;
        for (int i = 0; i < n; ++i) { 
            dp[i + 1] = 0;
            for (int j = i, mx = 0; j >= i - k + 1 && j >= 0; --j) {
                mx = max(mx, arr[j]); // 一边枚举j,一边计算子数组的最大值
                dp[i + 1] = max(dp[i + 1], dp[j] + mx * (i - j + 1));
            } 
        }
        return dp[n];
    }
};
*/