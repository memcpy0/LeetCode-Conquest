/*
** Problem: https://leetcode.cn/problems/longest-subsequence-with-limited-sum/
** Article: https://memcpy0.blog.csdn.net/article/details/129633270
** Author: memcpy0
*/
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end()); // O(nlogn)
        int n = nums.size(), m = queries.size();
        vector<int> ps(n + 1), ans(m);
        for (int i = 0; i < n; ++i) ps[i + 1] = ps[i] + nums[i]; // O(n)
        for (int i = 0; i < m; ++i) {
            int q = queries[i];
            // 找到ps中第一个大于q的值v的位置i
            // v是ps的前缀和,v>q说明到ps[i]的元素和>q,于是到ps[i-1]的元素和<=q
            ans[i] = upper_bound(ps.begin(), ps.begin() + n + 1, q) - ps.begin() - 1;
        }
        return ans;
    }
};