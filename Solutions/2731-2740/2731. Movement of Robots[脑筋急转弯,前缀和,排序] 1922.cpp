/*
** Problem: https://leetcode.cn/problems/movement-of-robots/
** Article: https://memcpy0.blog.csdn.net/article/details/133759038
** Author: memcpy0
*/
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = (long long) nums[i] + d * ((s[i] & 2) - 1); // L=-1,R=1
        sort(a.begin(), a.end());

        long long ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + i * a[i] - sum) % MOD;
            sum += a[i];
        }
        return ans;
    }
};