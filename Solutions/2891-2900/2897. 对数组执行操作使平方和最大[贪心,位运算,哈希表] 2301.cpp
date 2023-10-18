/*
** Problem: https://leetcode.cn/problems/apply-operations-on-array-to-maximize-sum-of-squares/
** Article: https://memcpy0.blog.csdn.net/article/details/133909698
** Author: memcpy0
*/
// BEST
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int cnt[31] {};
        for (int num : nums)
            for (int i = 0; i < 31; ++i)
                cnt[i] += ((num >> i) & 1);
        long long ans = 0;
        const int MOD = 1e9 + 7;
        while (k--) {
            int x = 0;
            for (int i = 0; i < 31; ++i) {
                if (cnt[i]) {
                    x |= 1 << i;
                    cnt[i]--;
                }
            }
            ans = (ans + (long long)x * x) % MOD;
        }
        return ans;
    }
};