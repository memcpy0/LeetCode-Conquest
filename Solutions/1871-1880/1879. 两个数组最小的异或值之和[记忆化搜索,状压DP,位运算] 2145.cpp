/*
** Problem: https://leetcode.cn/problems/minimum-xor-sum-of-two-arrays/
** Article: https://memcpy0.blog.csdn.net/article/details/133968802
** Author: memcpy0
*/
// BEST: 记忆化搜索
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> memo(n, vector<int>(1 << n, INT_MAX));
        // memo[i][j]表示在0~i在 j 代表的元素被选中时的最小异或值之和
        function<int(int, int)> f = [&](int i, int j) -> int {
            if (i < 0) return 0;
            int &ans = memo[i][j];
            if (ans != INT_MAX) return ans;
            for (int k = 0; k < n; ++k) 
                if ((j >> k) & 1) 
                    ans = min(ans, f(i - 1, j ^ (1 << k)) + (nums1[i] ^ nums2[k]));
            return ans;
        };
        return f(n - 1, (1 << n) - 1);
    }
};
// O(n)空间
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> f(1 << n, INT_MAX);
        f[0] = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    f[mask] = min(f[mask], f[mask ^ (1 << i)] + (nums1[__builtin_popcount(mask) - 1] ^ nums2[i]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
};